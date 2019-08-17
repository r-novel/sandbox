#include <stdio.h>
#include <stdint.h>


/*
        FLV HEADER                                         FLV BODY
    +---------------+  +--------+--------+--------+--------+     +-----------+--------+---------+
    |               |  |  prev  |  flv   |  prev  |  flv   |     |  prev     |  flv   |  prev   |
    |               |  |  tag   |  tag   |  tag   |  tag   | ... |  tag      |  tag   |  tag    |
    |               |  |  size0 |   #1   |  size1 |  #2    |     |  sizeN-1  |  #N    |  sizeN  |
    +---------------+  +--------+--------+--------+--------+     +-----------+--------+---------+

*/


#pragma pack(push, 1)
typedef struct {
    uint8_t                         signature[3];
    uint8_t                         version;
    uint8_t                         type_flags;
    uint32_t                        offset;
} flv_header_t;

typedef struct {
    uint8_t                         type;
    uint32_t                        data_size:24;
    uint32_t                        timestamp;                /* 24 bit of timestamp; 8 bits of extension; */
    uint32_t                        stream_id:24;
    void                           *data;
} flv_tag_t;

typedef struct {
    uint8_t                         sound_format:4;
    uint8_t                         sound_rate:2;
    uint8_t                         sound_size:1;
    uint8_t                         sound_type:1;
    uint8_t                        *sound_data;               /* uint8_t sound_data[flv_tag_t->data_size]; */
} flv_audio_data_t;

typedef struct {
    uint8_t                         aac_packet_type;
    void                           *aac_data;
} flv_audio_aac_packet_t;


typedef struct {
    uint8_t                         frame_type:4;
    uint8_t                         codec_id:4;
    void                           *video_data;
} flv_video_data_t;

typedef struct {
    uint8_t                         avc_packet_type;
    int32_t                         composition_time;
    void                           *data;
} flv_video_avc_packet_t;
#pragma pack(pop)


int main(int argc, char** argv) {
  return 0;
}
