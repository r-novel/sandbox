#include <curl/curl.h>
#include <stdio.h>

void usage() {
  fprintf(stdout, "usage:\n");
  fprintf(stdout, "./out <url>\n");
}

int main(int argc, char** argv) {
  if (argc < 2) {
    usage();
    return 0;
  }

	CURL* handle = curl_easy_init();
  FILE* fd;
	CURLcode res;
  char *location;
  unsigned resp;
	curl_easy_setopt(handle, CURLOPT_URL, argv[1]);
	res = curl_easy_perform(handle);

	if (res != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
	else {
      res = curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &resp);
      if((res == CURLE_OK) && ((resp / 100) != 3))
        fprintf(stderr, "Not a redirect.\n");
      else {
        res = curl_easy_getinfo(handle, CURLINFO_REDIRECT_URL, &location);
        if((res == CURLE_OK) && location) {
        	fd = fopen("./downloaded", "w");
          curl_easy_setopt(handle, CURLOPT_URL, location);
          curl_easy_setopt(handle, CURLOPT_WRITEDATA, fd);
          curl_easy_perform(handle);
        }
      }
    }

	curl_easy_cleanup(handle);
  fclose(fd);
	return 0;
}
