#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *word_groups[] = {
	"zxcvbnmZXCVBNM",
	"asdfghjklASDFGHJKL",
	"qwertyuiopQWERTYUIOP",
	NULL
};


int find_group_index(char c, char** words) {

	int index = 0;

	while (word_groups[index] != NULL) {
		if (strchr(word_groups[index], c)) {
			return index;
		}
		index++;
	}
	return -1;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {

	int i, count, num_match = 0;
	char *wordP;
	int group_index = -1;
	bool is_match;
	bool *match_array = malloc(sizeof(bool) * wordsSize);
	char **result = NULL;

	if (match_array == NULL) {
		return NULL;
	}

	memset(match_array, 0, sizeof(bool) * wordsSize);

	for (i = 0; i < wordsSize; i++) {

		if (words[i][0] == '\0') continue;

		group_index = find_group_index(words[i][0], word_groups);
		if (group_index == -1) continue;

		wordP = &words[i][0];

		is_match = true;

		while (*wordP) {
			if (group_index != find_group_index(*wordP, word_groups)) {
				is_match = false;
				break;
			} 
			wordP++;
		}

		if (is_match) {
			match_array[i] = true;
			num_match++;
		}
	}

	/* Allocate array */
	result = malloc(sizeof(char*) * num_match);
	for (i = 0, count = 0; i < wordsSize; i++) {

		if (match_array[i]) {
			result[count] = malloc(strlen(words[i])+1);
			if (result[count] == NULL) {
				return NULL;
			}
			strncpy(result[count], words[i], strlen(words[i])+1);
			count++;
		}
	}

	free(match_array);

	*returnSize = num_match;

	return result;
}

int main() {

	char *test_words[] = { "Hello", "Alaska", "Dad", "Peace" };
	char **result = NULL;
	int ret_size = 0;
	int i;

	result = findWords(test_words, 4, &ret_size);

	for (i = 0; i < ret_size; i++) {
		printf("=> %s\n", result[i]);
	}

	return 0;
}
