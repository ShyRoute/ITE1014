#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct _time {
	int minute;
	int second;
} Time;

typedef struct _song {
	char title[100];
	char artist[100];
	Time length;
} Song;

typedef struct _songlist {
	Song *songs;
	int size;
	int capacity;
} SongList;

SongList dataLoad(void); // 초기 텍스트 파일에서 노래를 입력받아 저장하는 함수
void datasave(SongList); // 프로그램 종료 시, 텍스트 파일에 노래 목록을 저장하는 함수
void printMenu(void); // 메인 메뉴를 출력하는 함수
void printSong(Song *); // 특정 노래의 제목, 가수, 곡 길이를 출력하는 함수
void printSongMenu(void); // 노래 검색 시 메뉴를 출력하는 함수
Song *searchsong(SongList, char *, char *); // 특정 제목, 가수의 노래를 목록에서 검색하는 함수
void editSong(Song *); // 특정 노래의 정보를 수정하는 함수
void deleteSong(SongList *, Song *); // 특정 노래를 목록에서 제거하는 함수
void addSong(SongList *); // 새로운 노래를 목록에 추가하는 함수
void printAllSongs(SongList); // 목록에 있는 모든 노래를 출력하는 함수
void deleteAll(SongList *); // 목록에 있는 모든 노래를 제거하는 함수

int main(void) {
	int selectMenu, select, check, newMinute, newSecond;
	char newTitle[100], newArtist[100];
	Song *find;
	printf("===== Mini Music Library =====\n\n");
	SongList data = dataLoad(); // 초기 텍스트 파일에서 노래 목록을 입력받음
	while(1) {
		printMenu();
		check = scanf(" %d", &selectMenu);
		if(check != 1 || selectMenu < 0 || selectMenu > 4) { // 0~4 사이의 정수만 입력
			printf("[ERROR] scanf error\n\n");
			while(getchar() != '\n');
			continue;
		}
		switch(selectMenu) { // 입력 메뉴에 따른 실행문
			case 1:
				printf("Input title : ");
				scanf(" %[^\n]s", newTitle);
				printf("Input artist : ");
				scanf(" %[^\n]s", newArtist);
				find = searchsong(data, newTitle, newArtist); // 노래를 검색하는 함수
				if(find == NULL) {
					printf("Cannot find\n");
					break; // 노래를 못찾을 시 처음으로
				}
				printSong(find); // 찾은 노래를 출력
				printSongMenu();
				scanf(" %d", &select); // 찾은 노래에 대한 메뉴 선택
				switch(select) {
					case 1:
						editSong(find); // 노래 수정
						break;

					case 2:
						deleteSong(&data, find); // 노래 삭제
						break;

					case 0:
						break;
				}
				break;

			case 2:
				addSong(&data); // 목록에 새로운 노래를 추가
				break;

			case 3:
				printAllSongs(data); // 목록에 있는 모든 곡들을 출력
				break;

			case 4:
				deleteAll(&data); // 목록에 있는 모든 곡들을 삭제
				break;

			case 0:
				datasave(data); // 프로그램 종료 메뉴, 목록에 있는 노래들을 텍스트 파일에 저장
				break;
		}
		if(selectMenu == 0) {
			free(data.songs); // 프로그램 종료 시, 동적 할당 시킨 메모리를 정리
			printf("Good Bye!\n\n");
			break;
		}
	}
}

SongList dataLoad(void) { // 초기 텍스트 파일에서 노래를 입력받아 저장하는 함수
	int num = 0, i;
	FILE *data = NULL;
	data = fopen("data.txt", "r"); // 미리 존재하는 파일을 가져옴
	if(data == NULL) {
		printf("[ERROR] open error. Making new file..\n\n");
		data = fopen("data.txt", "w+"); // 파일이 없으면 새로 만듬
		num = 0;
	} else {
		fscanf(data, " %d", &num); // 첫 줄에서 노래의 개수를 입력받음
	}
	SongList filedata;
	filedata.songs = (Song *)malloc(sizeof(Song) * num); // 노래의 개수만큼 동적 할당
	for(i = 0; i < num; i++) { // 노래 목록에 제목, 가수, 곡 길이를 파일에서 입력받음
		fscanf(data, " %d", &filedata.songs[i].length.minute);
		fscanf(data, " %d", &filedata.songs[i].length.second);
		fscanf(data, " %[^\n]s", filedata.songs[i].title);
		fscanf(data, " %[^\n]s", filedata.songs[i].artist);
	}
	filedata.capacity = num;
	filedata.size = num;
	if(fclose(data) != 0) { // 파일을 닫는 과정
		printf("[ERROR] close error\n\n");
	}
	return filedata;
}

void datasave(SongList f) { // 프로그램 종료 시, 텍스트 파일에 노래 목록을 저장하는 함수
	FILE *data = NULL;
	data = fopen("data.txt", "w"); // 쓰기 모드로 텍스트 파일을 불러옴
	fprintf(data, "%d\n", f.size);
	for(int i = 0; i < f.capacity; i++) { // 0분 0초가 아닌 노래들을 파일에 출력
		if(f.songs[i].length.minute != 0 && f.songs[i].length.second != 0) {
			fprintf(data, "%d %d\n", f.songs[i].length.minute, f.songs[i].length.second);
			fprintf(data, "%s\n%s\n", f.songs[i].title, f.songs[i].artist);
		}
	}
	if(fclose(data) != 0) { // 파일을 닫는 과정
		printf("[ERROR] close error\n\n");
	}
}

void printMenu(void) {
	printf("=============================\n");
	printf("1. Search\n");
	printf("2. New Song\n");
	printf("3. Print All\n");
	printf("4. Delete All\n");
	printf("0. Exit\n");
	printf("=============================\n");
	printf(">>> ");
}

void printSong(Song *s) { // 노래의 제목, 가수, 곡 길이를 출력
	printf("%s - %s (%d:%d)\n", s->artist, s->title, s->length.minute, s->length.second);
}

void printSongMenu(void) {
	printf("=============================\n");
	printf("1. Edit\n");
	printf("2. Delete\n");
	printf("0. Previous\n");
	printf("=============================\n");
	printf(">>> ");
}

Song *searchsong(SongList d, char *title, char *artist) { // 노래를 검색
	int i = 0;
	while(i < d.capacity) { // 노래를 찾을 때 까지 반복, 0분 0초의 경우 검색하지 않음
		if(strcmp(d.songs[i].title, title) == 0 && strcmp(d.songs[i].artist, artist) == 0) {
			if(d.songs[i].length.minute != 0 && d.songs[i].length.second != 0) {
				return &d.songs[i];
			}
		}
		i++;
	}
	return NULL;
}

void editSong(Song *s) { // 검색한 노래를 수정하는 함수
	int sec;
	printf("Input new title : ");
	scanf(" %[^\n]s", s->title);
	printf("Input new artist : ");
	scanf("  %[^\n]s", s->artist);
	while(1) { // 입력한 second가 0초와 60초 사이에서 입력받을 때 까지 반복
		printf("Input new length - minute : ");
		scanf(" %d", &s->length.minute);
		printf("Input new length - second : ");
		scanf(" %d", &sec);
		if(sec >= 60 || sec < 0) {
			printf("<ERROR> length error\n\n");
			continue;
		} else {
			s->length.second = sec;
			break;
		}
	}
}

void deleteSong(SongList *d, Song *s) {
	d->size--; // size(실제로 있는 곡의 수)를 1 감소
	int i = 0;
	while(i < d->capacity) {
		if(strcmp(d->songs[i].title, s->title) == 0 && strcmp(d->songs[i].artist, s->artist) == 0) {
			d->songs[i].length.minute = 0;
			d->songs[i].length.second = 0; // 입력한 곡을 찾아서 0분 0초로 변경
		}
		i++;
	}
}

void addSong(SongList *d) {
	int sec, i = 0;
	char newTitle[100], newArtist[100];
	Song *result;
	int n = d->capacity;
	d->capacity++; // size와 capacity를 1씩 증가
	d->size++;
	d->songs = (Song *)realloc(d->songs, sizeof(Song) * d->capacity); // 1 증가한 만큼 새로 동적 할당
	while(1) {
		printf("Input title : ");
		scanf(" %[^\n]s", newTitle);
		printf("Input artist : ");
		scanf(" %[^\n]s", newArtist);
		result = searchsong(*d, newTitle, newArtist);
		if(result != NULL) { // 찾은 노래가 있을때(NULL 이 아닐때)
			if(result->length.minute == 0 && result->length.second == 0) {
				break; // 0분 0초면 없는 노래로 취급하고 새로운 노래를 입력받음
			}
			printf("<ERROR> Already exist\n\n"); // 그 외에는 이미 존재하므로 다시 입력
			continue;
		}
		break;
	}
	strcpy(d->songs[n].title, newTitle);
	strcpy(d->songs[n].artist, newArtist); // 새로운 노래의 제목과 가수
	while(1) {
		printf("Input length - minute : ");
		scanf(" %d", &d->songs[n].length.minute);
		printf("Input length - second : ");
		scanf(" %d", &sec);
		if(sec >= 60 || sec < 0) { // second가 60 이상이거나 음수일 시 재입력
			printf("<ERROR> length error\n\n");
			continue;
		} else {
			d->songs[n].length.second = sec;
			break;
		}
	}
}

void printAllSongs(SongList d) {
	if(d.size == 0) { // 노래가 없을 때
		printf("<ERROR> No song in list\n\n");
		return;
	}
	for(int i = 0; i < d.capacity; i++) { // 0분 0초가 아닌 노래들을 출력
		if(d.songs[i].length.minute != 0 && d.songs[i].length.second != 0) {
			printSong(&d.songs[i]);
		}
	}
}

void deleteAll(SongList *d) {
	for(int i = 0; i < d->capacity; i++) { // 모든 노래의 시간을 0분 0초로 변경
		d->songs[i].length.minute = 0;
		d->songs[i].length.second = 0;
	}
	d->size = 0; // size(실제 존재하는 음악의 수)를 0으로 변경
}
