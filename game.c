#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

// GLOVAL VARIABLES
char secretWord[20];
char kicks[26];
int kickGiven = 0;

void opening() {
	printf("-+-----------------+-\n");
	printf(" |  Jogo da Forca  | \n");
	printf("-+-----------------+-\n\n");
}

void kickCapture() {
	char kick;
	scanf(" %c", &kick);

	kicks[kickGiven] = kick;
	kickGiven++;
}

int alreadyKicked(char word) {
	int find = 0;

	for (int j = 0; j < kickGiven; j++) {
		if (kicks[j] == word) {
			find = 1;
			break;
		}
	}

	return find;
}

void draw() {
	for (int i = 0; i < strlen(secretWord); i++) {
		int find = alreadyKicked(secretWord[i]);

		if (find) {
			printf("%c ", secretWord[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

void selectWord() {
	FILE* file;
	file = fopen("words.txt", "r");

	if (file == 0) {
		printf("Desculpe, banco de dados nao disponivel.\n\n");
		exit(1);
	}

	int quantityWords;
	fscanf(file, "%d", &quantityWords);

	srand(time(0));
	int random = rand() % quantityWords;

	for (int i = 0; i <= random; i++) {
		fscanf(file, "%s", secretWord);
	}

	fclose(file);
}

void addWord() {
	char opc;

	printf("Voce deseja inserir alguma palavra? (Y/N)");
	scanf(" %c", &opc);

	if (opc == 'Y') {
		char newWord[20];
		printf("Qual e a nova palavra? ");
		scanf("%s", newWord);

		FILE* file;
		file = fopen("words.txt", "r+");

		if (file == 0) {
			printf("Desculpe, banco de dados nao disponivel.\n\n");
			exit(1);
		}

		int quantity;
		fscanf(file, "%d", &quantity);
		quantity++;

		fseek(file, 0, SEEK_SET);
		fprintf(file, "%d", quantity);

		fseek(file, 0, SEEK_END);
		fprintf(file, "\n%s", newWord);

		fclose(file);
	}
}

int hanged() {
	int errors = 0;
	for (int i = 0; i < kickGiven; i++) {
		int exists = 0;
		for (int j = 0; j < strlen(secretWord); j++) {
			if (kicks[i] == secretWord[j]) {
				exists = 1;
				break;
			}
		}

		if (!exists) {
			errors++;
		}
	}

	return errors >= 5;
}

int win() {
	for (int i = 0; i < strlen(secretWord); i++) {
		if(!alreadyKicked(secretWord[i])) {
			return 0;
		}
	}
	return 1;
}

int main() {
	selectWord();
	opening();

	do {
		draw();
		kickCapture();
	} while (!win() && !hanged());
	addWord();
}
