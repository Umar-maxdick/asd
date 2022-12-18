#pragma warning (disable : 4996)
//сортировка слияниями
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
int split(FILE* f, FILE* f1, FILE* f2) {
	int n = 0;
	int x = 0;
	rewind(f);
	//fgets(x,1, f);
	fscanf(f, "%d", &x);
	while (!feof(f)) {
		//fputs(x,f1);

		fprintf(f1, "%d ", x);
		//fgets(x, 1, f);
		fscanf(f, "%d", &x);
		if (!feof(f)) {
			//fputs(x,f2);
			fprintf(f2, "%d ",x);
			fscanf(f, "%d", &x);
		}
		//printf("n = %d", n);
		n++;

	}
	//printf("n = %d", n);
	return(n > 1);
}
void merge(FILE* f1, FILE* f2, FILE* fr) {
	int x1, x2;
	rewind(f1);
	rewind(f2);
	rewind(fr);
	fscanf(f1, "%d", &x1);
	fscanf(f2, "%d", &x2);
	//printf("x2 = %d\n", x2);
	//printf("x1 = %d\n", x1);
	//fgets(x1, 1, f1);
	//fgets(x2, 1, f2);
	while (!feof(f1) || !feof(f2)) {
		if (feof(f1)) {
			//fputs(x2,fr);
			//fgets(x2, 1, f2);
			fprintf(fr, "%d ", x2);
			//printf("x2 = %d\n", x2);
			fscanf(f2, "%d", &x2);
		}else if(feof(f2)){
			//fputs(x1, fr);
			//fgets(x1, 1, f1);
			fprintf(fr, "%d ", x1);
			//printf("x1 = %d\n", x1);
			fscanf(f1, "%d", &x1);
		}
		else if (x1 < x2) {
			fprintf(fr, "%d ", x1);
			fscanf(f1, "%d", &x1);
		}
		else {
			//fputs(x2, fr);
			//fgets(x2, 1, f2);
			fprintf(fr, "%d ", x2);
			fscanf(f2, "%d", &x2);
		}
	}
}
void sort_merge(FILE* f)
{
	FILE* f1 = tmpfile();
	FILE* f2 = tmpfile();
	if (split(f, f1, f2))
	{
		sort_merge(f1);
		sort_merge(f2);
	}
	merge(f1, f2, f);
	fclose(f1);
	fclose(f2);
}

int main() {
	int n;
	srand(time(NULL));
	system("chcp 1251");
	system("cls");
	FILE* fx = fopen("1.txt", "r+b");
	sort_merge(fx);
	fclose(fx);
	return 0;

}