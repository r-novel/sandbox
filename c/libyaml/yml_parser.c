#include <yaml.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct user_t {
	char*           				login;
	char*										password;
	int 										uid;
	int 										guid;
	char* 									shell;
};

enum state_t {
													START,
													ACCEPT_SECTION,
													ACCEPT_LIST,
													ACCEPT_VALUES,
													ACCEPT_KEY,
													ACCEPT_VALUE,
													STOP,
													ERROR,
};

struct parser_state_t {
	enum 										state_t state;
	int 										accepted;
	int 										error;
	char*										key;
	char*										value;
	struct user_t 					data;
};

int consume_event(struct parser_state_t* s, yaml_event_t* event)
{
	s->accepted = 0;
	switch (s->state) {
	case START:
		switch (event->type) {
		case YAML_MAPPING_START_EVENT:
			s->state = ACCEPT_SECTION;
			break;
		case YAML_SCALAR_EVENT:
			fprintf(stderr, "Ignoring unexpected scalar: %s\n",
					(char*)event->data.scalar.value);
			break;
		case YAML_SEQUENCE_START_EVENT:
			fprintf(stderr, "Unexpected sequence.\n");
			s->state = ERROR;
			break;
		case YAML_STREAM_END_EVENT: s->state = STOP; break;
		default:
			break;
		}
		break;
	case ACCEPT_SECTION:
		switch (event->type) {
		case YAML_SCALAR_EVENT:
			if (strcmp((char*)event->data.scalar.value, "users") == 0) {
			   s->state = ACCEPT_LIST;
			} else {
			   fprintf(stderr, "Unexpected scalar: %s\n",
					  (char*)event->data.scalar.value);
			   s->state = ERROR;
			}
			break;
		default:
			fprintf(stderr, "Unexpected event while getting scalar: %d\n", event->type);
			s->state = ERROR;
			break;
		}
		break;
	case ACCEPT_LIST:
		switch (event->type) {
		case YAML_SEQUENCE_START_EVENT: s->state = ACCEPT_VALUES; break;
		default:
			fprintf(stderr, "Unexpected event while getting sequence: %d\n", event->type);
			s->state = ERROR;
			break;
		}
		break;
	case ACCEPT_VALUES:
		switch (event->type) {
		case YAML_MAPPING_START_EVENT:
			memset(&(s->data), 0, sizeof(s->data));
			s->state = ACCEPT_KEY;
			break;
		case YAML_SEQUENCE_END_EVENT: s->state = START; break;
		case YAML_DOCUMENT_END_EVENT: s->state = START; break;
		default:
			fprintf(stderr, "Unexpected event while getting mapped values: %d\n",
					event->type);
			s->state = ERROR;
			break;
		}
		break;
	case ACCEPT_KEY:
		switch (event->type) {
		case YAML_SCALAR_EVENT:
			s->key = strdup((char*)event->data.scalar.value);
			s->state = ACCEPT_VALUE;
			break;
		case YAML_MAPPING_END_EVENT:
			s->accepted = 1;
			s->state = ACCEPT_VALUES;
			break;
		default:
			fprintf(stderr, "Unexpected event while getting key: %d\n",
					event->type);
			s->state = ERROR;
			break;
		}
		break;
	case ACCEPT_VALUE:
		switch (event->type) {
		case YAML_SCALAR_EVENT:
			s->value = (char*)event->data.scalar.value;
			if (strcmp(s->key, "login") == 0) {
				s->data.name = strdup((char*)s->value);
			} else if (strcmp(s->key, "password") == 0) {
				s->data.color = strdup((char*)s->value);
			} else if (strcmp(s->key, "shell") == 0) {
				s->data.color = strdup((char*)s->value);
			} else if (strcmp(s->key, "uid") == 0) {
				s->data.count = atoi(s->value);
			} else if (strcmp(s->key, "guid") == 0) {
				s->data.count = atoi(s->value);
			} else {
				fprintf(stderr, "Ignoring unknown key: %s\n", s->key);
			}
			free(s->key);
			s->state = ACCEPT_KEY;
			break;
		default:
			fprintf(stderr, "Unexpected event while getting value: %d\n",
					event->type);
			s->state = ERROR;
			break;
		}
		break;
	case ERROR:
	case STOP:
		break;
	}
	return (s->state == ERROR ? 0 : 1);
}

int main(int argc, char** argv)
{
	yaml_parser_t parser;
	yaml_event_t event;
	struct parser_state state = {.state=START, .accepted=0, .error=0};
	struct user_t data[64];
	int i = 0;

	memset(data, 0, sizeof(data));
	yaml_parser_initialize(&parser);
	yaml_parser_set_input_file(&parser, stdin);

	do {
		if (!yaml_parser_parse(&parser, &event)) {
			goto error;
		}
		if (!consume_event(&state, &event)) {
			goto error;
		}
		if (state.accepted && i < sizeof(data)/sizeof(*data)) {
			data[i].login = state.data.login;
			data[i].password = state.data.password;
			data[i].shell = state.data.shell;
			data[i].uid = state.data.uid;
			data[i].guid = state.data.guid;
			printf("data[%d]={login=%s, pswd=%s, shell=%s, uid=%d, guid=%d }\n",
				i, data[i].login, data[i].password, data[i].shell, data[i].uid, data[i].guid);
			i++;
		}
		yaml_event_delete(&event);
	} while (state.state != STOP);

	yaml_parser_delete(&parser);
	return 0;

error:
	yaml_parser_delete(&parser);
	return 1;
}
