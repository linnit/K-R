#include <stdio.h>
#define MAXLINE 1000
#define TABSPACE 4
#define INBLANK 1
#define OUTBLANK 0

char line[MAXLINE];

int getline_ryan(void);
int conv_spaces(void);

int conv_spaces() {
	int i, j, spaces;
	int blank_count = 0;
	int state = OUTBLANK;

	for (i = 0; line[i] != '\0'; ++i) {
		if (line[i] != ' ') {
			state = OUTBLANK;

			if (blank_count > 0) {
				if (blank_count >= 4) {
					printf("\t");
					blank_count = blank_count - 4;
				}
				for (j = 0; j < blank_count; ++j)
					printf(" ");
			}

			printf("%c", line[i]);

			blank_count = 0;
		} else {
			state = INBLANK;
			++blank_count;
		}

	}
}

int main() {
	int len;

	while ((len = getline_ryan()) > 0) {
		conv_spaces();
	}
	
	return 0;
}

/* getline_ryan: read a line into s, return length */
int getline_ryan() {
	int c, i;

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}

	if (i == (MAXLINE - 1)) {
		while((c = getchar()) != EOF) {
			++i;
		}
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

