//회문 stack사용해서 확인하기 (대문자, 기호 , 공백 고려X)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

typedef int element;

typedef struct {
	element data[100];
	int top;
}stackType;

void init_stack(stackType* s) {
	s->top = -1;
}

int is_empty(stackType* s) {
	return (s->top == -1);
}
int is_full(stackType* s) {
	return (s->top == (MAX-1));
}

void push(stackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(stackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];

}

element peek(stackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}


int rotation(stackType* s, char* str) {
	char new_str[MAX] = { 0 };

	int i;
	int j = 0;

	for (i = 0; i < strlen(str); i++) {
		if (isalpha(str[i])) {
			new_str[j++] = tolower(str[i]);
		}
	}


	for (i = 0; i < j; i++) {
		push(s, new_str[i]);
	}

	for (i = 0; i < j; i++) {
		if (new_str[i] != pop(s)) {
			return 0;

		}
	}
	return 1;
}


int main() {
	stackType s;
	init_stack(&s);

	char answer[100] = { 0 };
	char str[MAX];
	int r = 0;

	while (strcmp(answer, "No") != 0) {
		printf("문자열을 입력하시오 : ");
		scanf_s("%[^\n]", str, MAX);

		//str[strlen(str) - 1] = '\0';
		r = rotation(&s, str);

		if (r == 1) {
			printf("회문입니다.\n\n");
		}
		else {
			printf("회문이 아닙니다.\n\n");
		}

		printf("계속 입력하시겠습니까(Yes,No): ");
		scanf_s("%s", answer, MAX);
		printf("\n");

		while (getchar() != '\n');

	}


	return 0;
}