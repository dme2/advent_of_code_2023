#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_number(char* line, int i, int j, int* result) {
  int res;
  res = (int)atoi(&line[j]);
  *result = res;
}

int main(void)
{
    FILE *fp;
	char *line = NULL;
    char lines[140][141];
    size_t len = 0;
    ssize_t read;

    fp = fopen("aoc3.txt", "r");
	int i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
	  strcpy(lines[i], line);
	  i++;
    }
    fclose(fp);
	int result = 0;
	for (int i = 0; i < 140; i++) {
	  int num = 0;
	  int seen_digit = 0;
	  int valid = 0;
	  for (int j = 0; j < 141; j++) {
		if (isdigit(lines[i][j])) {
		  if (valid == 1)
			continue;
		  if (seen_digit == 0) {
			parse_number(lines[i], i, j, &num);
			seen_digit=1;
		  }
		  // check up
		  if (i > 0) {
			if (lines[i-1][j] == '*' || lines[i-1][j] == '=' || lines[i-1][j] == '&'
				|| lines[i-1][j] == '$' || lines[i-1][j] == '/' || lines[i-1][j] == '@'
				|| lines[i-1][j] == '-' || lines[i-1][j]=='+' || lines[i-1][j] == '%'
				|| lines[i-1][j] == '#'){
			  valid = 1;
			  result+=num;
			  continue;
			}
		  }
		  // down
		  if (i < 140) {
			if (lines[i+1][j] == '*' || lines[i+1][j] == '=' || lines[i+1][j] == '&'
				|| lines[i+1][j] == '$' || lines[i+1][j] == '/' || lines[i+1][j] == '@'
				|| lines[i+1][j] == '-' || lines[i+1][j]=='+' || lines[i+1][j] == '%'
				|| lines[i+1][j] == '#'){
			  valid = 1;
			  result+=num;
			  continue;
			}
		  }
		  // left
		  if (j > 0) {
			if (lines[i][j-1] == '*' || lines[i][j-1] == '=' || lines[i][j-1] == '&'
				|| lines[i][j-1] == '$' || lines[i][j-1] == '/' || lines[i][j-1] == '@'
				|| lines[i][j-1] == '-' || lines[i][j-1]=='+' || lines[i][j-1] == '%'
				|| lines[i][j-1] == '#'){
			  valid = 1;
			  result+=num;
			  continue;
			}
		  }
		  //right
		  if (j < 141) {
			if (lines[i][j+1] == '*' || lines[i][j+1] == '=' || lines[i][j+1] == '&'
				|| lines[i][j+1] == '$' || lines[i][j+1] == '/' || lines[i][j+1] == '@'
				|| lines[i][j+1] == '-' || lines[i][j+1]=='+' || lines[i][j+1] == '%'
				|| lines[i][j+1] == '#'){
			  valid = 1;
			  result+=num;
			  continue;
			}
		  }
	    
		  //diag up left
		  if (j > 0 && i > 0) {
			if (lines[i-1][j-1] == '*' || lines[i-1][j-1] == '=' || lines[i-1][j-1] == '&'
				|| lines[i-1][j-1] == '$' || lines[i-1][j-1] == '/' || lines[i-1][j-1] == '@'
				|| lines[i-1][j-1] == '-' || lines[i-1][j-1]=='+' || lines[i-1][j-1] == '%'
				|| lines[i-1][j-1] == '#'){
			  valid = 1;
			  result+=num;
			  continue;
			}
		  }

		  // diag up right
		  if (j < 141 && i > 0) {
			if (lines[i-1][j+1] == '*' || lines[i-1][j+1] == '=' || lines[i-1][j+1] == '&'
				|| lines[i-1][j+1] == '$' || lines[i-1][j+1] == '/' || lines[i-1][j+1] == '@'
				|| lines[i-1][j+1] == '-' || lines[i-1][j+1]=='+' || lines[i-1][j+1] == '%'
				|| lines[i-1][j+1] == '#'){
			  valid = 1;
			  result+=num;
			  continue;
			}
		  }

		  // diag down right
		  if (j < 141 && i < 140) {
			if (lines[i+1][j+1] == '*' || lines[i+1][j+1] == '=' || lines[i+1][j+1] == '&'
				|| lines[i+1][j+1] == '$' || lines[i+1][j+1] == '/' || lines[i+1][j+1] == '@'
				|| lines[i+1][j+1] == '-' || lines[i+1][j+1]=='+' || lines[i+1][j+1] == '%'
				|| lines[i+1][j+1] == '#'){
			  valid = 1;
			  result+=num;
			  continue;
			}
		  }
		  // diag down left
		  if (j > 0 && i < 140) {
			if (lines[i+1][j-1] == '*' || lines[i+1][j-1] == '=' || lines[i+1][j-1] == '&'
				|| lines[i+1][j-1] == '$' || lines[i+1][j-1] == '/' || lines[i+1][j-1] == '@'
				|| lines[i+1][j-1] == '-' || lines[i+1][j-1]=='+' || lines[i+1][j-1] == '%'
				|| lines[i+1][j-1] == '#'){
			  valid = 1;
			  result+=num;
			  continue;
			}
		  }
		}
		else {
		  seen_digit = 0;
		  valid = 0;
		}
	  }
	}
	printf("%i\n", result);
	return 0;
}
