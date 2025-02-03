#include <stdio.h>
#include <string.h>

int main() {
	char secretWord[20];

	// SPRINTF é a função para colocar uma 'string' dentro de um ARRAY
	sprintf(secretWord, "Giordano");

	int finish = 0;
	int hanged = 0;

	do {
		char kick;
		scanf("%c", &kick);

		for (int i = 0; i < strlen(secretWord); i++) {
			if (secretWord[i] == kick) {
				printf("A posicao %d tem a letra!\n", (i + 1));
			}
		}
	} while (!finish && !hanged);
}
