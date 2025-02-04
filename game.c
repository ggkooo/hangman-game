#include <stdio.h>
#include <string.h>

// GLOVAL VARIABLES
char secretWord[20];
char kicks[26];
int attempt = 0;

void opening() {
	printf("-+-----------------+-\n");
	printf(" |  Jogo da Forca  | \n");
	printf("-+-----------------+-\n\n");
}

void kickCapture() {
	char kick;
	scanf(" %c", &kick);

	kicks[attempt] = kick;
	attempt++;
}

int alreadyKicked(char word) {
	int find = 0;

	for (int j = 0; j < attempt; j++) {
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
	// SPRINTF é a função para colocar uma 'string' dentro de um ARRAY
	sprintf(secretWord, "Giordano");
}

int main() {
	int finish = 0;
	int hanged = 0;

	selectWord();
	opening();

	do {
		draw();

		kickCapture();

	} while (!finish && !hanged);
}
