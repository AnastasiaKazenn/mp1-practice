#include <stdio.h>
#define N 10

char* barcode_base[N] = { "1000", "1200", "1230", "1234", "1235", "1236", "1237", "1238", "1239", "1240" };
double sale_base[N] = { 1, 20, 30, 25, 15, 10, 5, 3, 9, 50 };
double cost_base[N] = { 70, 90, 40, 300, 25, 100, 100, 7, 150, 300 };
char* goods_base[N] = { "milk", "egg", "bread", "cheese", "water", "juice", "cookie", "package", "candies", "oil" };
int check[N] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int n, k;
float final_price = 0;// надо ли занулять?

void scan_barcode(char* barcode_base, int g);
void product_information(n);
void final_check();

int main()
{
	int answer;
	do {
		scan_barcode(barcode_base, N);
		product_information(k);
		printf("If you want to add a product, input 1. If you want to stop shopping, input 0\n");
		scanf("d\n", &answer);
	} while (answer == 1);
	void final_check();
	return 0;
}


void scan_barcode(char* barcode_base, int g)
{
	char barcode;
	int flag = 0, i = 0;
	printf("Input barcode:\n ");
	scanf("%c", &barcode);
	for (i ; i < g; i++)
	{
		if (barcode == barcode_base[i])
		{
			check[i]++;//кол-во этого товара;
			flag = 1;
			k = i;
			return k;
		}
	}
	if (flag == 0)
		printf("incorrect barcode\n");
}


void product_information(n)
{
	float discounted_price, final_price = 0;
	printf("product: %c\n", goods_base[n]);
	printf("cost: %f\n", cost_base[n]);
	printf("sale: %f\n", sale_base[n]);
	discounted_price = (cost_base[n] * sale_base[n] / 100.0);
	printf("cost: %f\n", discounted_price);
	printf("count: %d\n", check[n]);
	final_price = final_price + discounted_price;
}

void final_check()
{
	int i = 0;
	printf("....CHECK....\n");
	for (i; i < N; i++)
	{
		if (check[i] != 0);
			product_information(i);
	}
	printf("%f\n", final_price);
}