#include <stdio.h>
#include <string.h>

int main() {
	char secretWord[20];

	// SPRINTF é a função para colocar uma 'string' dentro de um ARRAY
	sprintf(secretWord, "Giordano");

	int finish = 0;
	int hanged = 0;

	char kicks[26];
	int attempt = 0;

	do {
		for (int i = 0; i < strlen(secretWord); i++) {
			int find = 0;

			for (int j = 0; j < attempt; j++) {
				if (kicks[j] == secretWord[i]) {
					find = 1;
					break;
				}
			}

			if (find) {
				printf("%c ", secretWord[i]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");

		char kick;
		scanf(" %c", &kick);

		kicks[attempt] = kick;
		attempt++;
	} while (!finish && !hanged);
}
