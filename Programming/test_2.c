#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "hacking.h"

#define FILENAME "/var/notes"

void fatal(char *);
int print_notes(int, int, char *);
int find_user_note(int, int);

int main(int argc, char *argv[]) {
    int fd, uid, note_uid=-1, note_length, printing=1;
    unsigned char byte;
    char note_buffer[100], searchstring[100];

    if(argc > 1)
        strcpy(searchstring, argv[1]);
    else
        searchstring[0] = 0;

    uid = getuid();
    fd = open(FILENAME, O_RDONLY);
    if(fd == -1)
        fatal("in main() while opening file for reading");

    while(printing)
        printing = print_notes(fd, uid, searchstring);
    printf("-------[ end of note data ]-------\n");
    close(fd);
    return 0;
}

int print_notes(int fd, int uid, char *stringsearch) {
    int note_length;
    char byte=0, note_buffer[100];

    note_length = find_user_note(fd, uid);
    if(note_length == -1)
        return 0;
    read(fd, note_buffer, note_length);
    note_buffer[note_length] = 0;

    if(search_note(note_buffer, stringsearch))
        printf(note_buffer);
    return 1;
}

int find_user_note(int fd, int user_id) {
    int note_uid=-1;
    unsigned char byte;
    int length;

    while(note_uid != user_id) {
        if(read(fd, &note_uid, 4) != 4)
            return -1;
        if(read(fd, &byte, 1) != 1)
            return -1;
        byte = length = 0;
        while(byte != '\n') {
            if(read(fd, &byte, 1) != 1)
                return -1;
            length++;
        }
    }
    lseek(fd, length * -1, SEEK_CUR);
    printf("[DEBUG] found a %d byte note for user id %d\n", length, note_uid);
    return length;
}

int search_note(char *note, char *keyword) {
    int i, keyword_length, match=0;

    keyword_length = strlen(keyword);
    if(keyword_length == 0)
        return 1;
    
    for(i=0; i < strlen(note); i++) {
        if(note[i] == keyword[match])
            match++;
        else{
            if(note[i] == keyword[0])
                match = 1;
            else
                match = 0;
        }
        if(match == keyword_length)
            return 1;
    }
    return 0;
}