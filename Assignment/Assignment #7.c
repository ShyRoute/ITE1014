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

SongList dataLoad(void); // �ʱ� �ؽ�Ʈ ���Ͽ��� �뷡�� �Է¹޾� �����ϴ� �Լ�
void datasave(SongList); // ���α׷� ���� ��, �ؽ�Ʈ ���Ͽ� �뷡 ����� �����ϴ� �Լ�
void printMenu(void); // ���� �޴��� ����ϴ� �Լ�
void printSong(Song *); // Ư�� �뷡�� ����, ����, �� ���̸� ����ϴ� �Լ�
void printSongMenu(void); // �뷡 �˻� �� �޴��� ����ϴ� �Լ�
Song *searchsong(SongList, char *, char *); // Ư�� ����, ������ �뷡�� ��Ͽ��� �˻��ϴ� �Լ�
void editSong(Song *); // Ư�� �뷡�� ������ �����ϴ� �Լ�
void deleteSong(SongList *, Song *); // Ư�� �뷡�� ��Ͽ��� �����ϴ� �Լ�
void addSong(SongList *); // ���ο� �뷡�� ��Ͽ� �߰��ϴ� �Լ�
void printAllSongs(SongList); // ��Ͽ� �ִ� ��� �뷡�� ����ϴ� �Լ�
void deleteAll(SongList *); // ��Ͽ� �ִ� ��� �뷡�� �����ϴ� �Լ�

int main(void) {
	int selectMenu, select, check, newMinute, newSecond;
	char newTitle[100], newArtist[100];
	Song *find;
	printf("===== Mini Music Library =====\n\n");
	SongList data = dataLoad(); // �ʱ� �ؽ�Ʈ ���Ͽ��� �뷡 ����� �Է¹���
	while(1) {
		printMenu();
		check = scanf(" %d", &selectMenu);
		if(check != 1 || selectMenu < 0 || selectMenu > 4) { // 0~4 ������ ������ �Է�
			printf("[ERROR] scanf error\n\n");
			while(getchar() != '\n');
			continue;
		}
		switch(selectMenu) { // �Է� �޴��� ���� ���๮
			case 1:
				printf("Input title : ");
				scanf(" %[^\n]s", newTitle);
				printf("Input artist : ");
				scanf(" %[^\n]s", newArtist);
				find = searchsong(data, newTitle, newArtist); // �뷡�� �˻��ϴ� �Լ�
				if(find == NULL) {
					printf("Cannot find\n");
					break; // �뷡�� ��ã�� �� ó������
				}
				printSong(find); // ã�� �뷡�� ���
				printSongMenu();
				scanf(" %d", &select); // ã�� �뷡�� ���� �޴� ����
				switch(select) {
					case 1:
						editSong(find); // �뷡 ����
						break;

					case 2:
						deleteSong(&data, find); // �뷡 ����
						break;

					case 0:
						break;
				}
				break;

			case 2:
				addSong(&data); // ��Ͽ� ���ο� �뷡�� �߰�
				break;

			case 3:
				printAllSongs(data); // ��Ͽ� �ִ� ��� ����� ���
				break;

			case 4:
				deleteAll(&data); // ��Ͽ� �ִ� ��� ����� ����
				break;

			case 0:
				datasave(data); // ���α׷� ���� �޴�, ��Ͽ� �ִ� �뷡���� �ؽ�Ʈ ���Ͽ� ����
				break;
		}
		if(selectMenu == 0) {
			free(data.songs); // ���α׷� ���� ��, ���� �Ҵ� ��Ų �޸𸮸� ����
			printf("Good Bye!\n\n");
			break;
		}
	}
}

SongList dataLoad(void) { // �ʱ� �ؽ�Ʈ ���Ͽ��� �뷡�� �Է¹޾� �����ϴ� �Լ�
	int num = 0, i;
	FILE *data = NULL;
	data = fopen("data.txt", "r"); // �̸� �����ϴ� ������ ������
	if(data == NULL) {
		printf("[ERROR] open error. Making new file..\n\n");
		data = fopen("data.txt", "w+"); // ������ ������ ���� ����
		num = 0;
	} else {
		fscanf(data, " %d", &num); // ù �ٿ��� �뷡�� ������ �Է¹���
	}
	SongList filedata;
	filedata.songs = (Song *)malloc(sizeof(Song) * num); // �뷡�� ������ŭ ���� �Ҵ�
	for(i = 0; i < num; i++) { // �뷡 ��Ͽ� ����, ����, �� ���̸� ���Ͽ��� �Է¹���
		fscanf(data, " %d", &filedata.songs[i].length.minute);
		fscanf(data, " %d", &filedata.songs[i].length.second);
		fscanf(data, " %[^\n]s", filedata.songs[i].title);
		fscanf(data, " %[^\n]s", filedata.songs[i].artist);
	}
	filedata.capacity = num;
	filedata.size = num;
	if(fclose(data) != 0) { // ������ �ݴ� ����
		printf("[ERROR] close error\n\n");
	}
	return filedata;
}

void datasave(SongList f) { // ���α׷� ���� ��, �ؽ�Ʈ ���Ͽ� �뷡 ����� �����ϴ� �Լ�
	FILE *data = NULL;
	data = fopen("data.txt", "w"); // ���� ���� �ؽ�Ʈ ������ �ҷ���
	fprintf(data, "%d\n", f.size);
	for(int i = 0; i < f.capacity; i++) { // 0�� 0�ʰ� �ƴ� �뷡���� ���Ͽ� ���
		if(f.songs[i].length.minute != 0 && f.songs[i].length.second != 0) {
			fprintf(data, "%d %d\n", f.songs[i].length.minute, f.songs[i].length.second);
			fprintf(data, "%s\n%s\n", f.songs[i].title, f.songs[i].artist);
		}
	}
	if(fclose(data) != 0) { // ������ �ݴ� ����
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

void printSong(Song *s) { // �뷡�� ����, ����, �� ���̸� ���
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

Song *searchsong(SongList d, char *title, char *artist) { // �뷡�� �˻�
	int i = 0;
	while(i < d.capacity) { // �뷡�� ã�� �� ���� �ݺ�, 0�� 0���� ��� �˻����� ����
		if(strcmp(d.songs[i].title, title) == 0 && strcmp(d.songs[i].artist, artist) == 0) {
			if(d.songs[i].length.minute != 0 && d.songs[i].length.second != 0) {
				return &d.songs[i];
			}
		}
		i++;
	}
	return NULL;
}

void editSong(Song *s) { // �˻��� �뷡�� �����ϴ� �Լ�
	int sec;
	printf("Input new title : ");
	scanf(" %[^\n]s", s->title);
	printf("Input new artist : ");
	scanf("  %[^\n]s", s->artist);
	while(1) { // �Է��� second�� 0�ʿ� 60�� ���̿��� �Է¹��� �� ���� �ݺ�
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
	d->size--; // size(������ �ִ� ���� ��)�� 1 ����
	int i = 0;
	while(i < d->capacity) {
		if(strcmp(d->songs[i].title, s->title) == 0 && strcmp(d->songs[i].artist, s->artist) == 0) {
			d->songs[i].length.minute = 0;
			d->songs[i].length.second = 0; // �Է��� ���� ã�Ƽ� 0�� 0�ʷ� ����
		}
		i++;
	}
}

void addSong(SongList *d) {
	int sec, i = 0;
	char newTitle[100], newArtist[100];
	Song *result;
	int n = d->capacity;
	d->capacity++; // size�� capacity�� 1�� ����
	d->size++;
	d->songs = (Song *)realloc(d->songs, sizeof(Song) * d->capacity); // 1 ������ ��ŭ ���� ���� �Ҵ�
	while(1) {
		printf("Input title : ");
		scanf(" %[^\n]s", newTitle);
		printf("Input artist : ");
		scanf(" %[^\n]s", newArtist);
		result = searchsong(*d, newTitle, newArtist);
		if(result != NULL) { // ã�� �뷡�� ������(NULL �� �ƴҶ�)
			if(result->length.minute == 0 && result->length.second == 0) {
				break; // 0�� 0�ʸ� ���� �뷡�� ����ϰ� ���ο� �뷡�� �Է¹���
			}
			printf("<ERROR> Already exist\n\n"); // �� �ܿ��� �̹� �����ϹǷ� �ٽ� �Է�
			continue;
		}
		break;
	}
	strcpy(d->songs[n].title, newTitle);
	strcpy(d->songs[n].artist, newArtist); // ���ο� �뷡�� ����� ����
	while(1) {
		printf("Input length - minute : ");
		scanf(" %d", &d->songs[n].length.minute);
		printf("Input length - second : ");
		scanf(" %d", &sec);
		if(sec >= 60 || sec < 0) { // second�� 60 �̻��̰ų� ������ �� ���Է�
			printf("<ERROR> length error\n\n");
			continue;
		} else {
			d->songs[n].length.second = sec;
			break;
		}
	}
}

void printAllSongs(SongList d) {
	if(d.size == 0) { // �뷡�� ���� ��
		printf("<ERROR> No song in list\n\n");
		return;
	}
	for(int i = 0; i < d.capacity; i++) { // 0�� 0�ʰ� �ƴ� �뷡���� ���
		if(d.songs[i].length.minute != 0 && d.songs[i].length.second != 0) {
			printSong(&d.songs[i]);
		}
	}
}

void deleteAll(SongList *d) {
	for(int i = 0; i < d->capacity; i++) { // ��� �뷡�� �ð��� 0�� 0�ʷ� ����
		d->songs[i].length.minute = 0;
		d->songs[i].length.second = 0;
	}
	d->size = 0; // size(���� �����ϴ� ������ ��)�� 0���� ����
}
