#include <stdio.h>
#define N 10
#define MAX_LEN 255

char* barcode_base[N] = { "1000", "1200", "1230", "1234", "1235", "1236", "1237", "1238", "1239", "1240" };
double sale_base[N] = { 1.0, 20.0, 30.0, 25.0, 15.0, 10.0, 5.0, 3.0, 9.0, 50.0 };
double cost_base[N] = { 70.0, 90.0, 40.0, 300.0, 25.0, 100.0, 100.0, 7.0, 150.0, 300.0 };
char* goods_base[N] = { "milk", "egg", "bread", "cheese", "water", "juice", "cookie", "package", "candies", "oil" };
int check[N] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
double final_price = 0.0;

int scan_barcode();
void product_information(int n);
void final_check();

int main()
{
	int answer = 1;
	do {
		int k = scan_barcode();
		if (k < 0)
		{
			continue;
		}
		product_information(k);
		printf("If you want to add a product, input 1. If you want to stop shopping, input 0\n");
		scanf("%d", &answer);
	} while (answer == 1);
	final_check();
	return 0;
}

int scan_barcode()
{
	char barcode[MAX_LEN];
	int i = 0;
	printf("Input barcode:\n");
	scanf("%s", barcode);
	for (; i < N; i++)
	{
		if (strcmp(barcode, barcode_base[i]) == 0)
		{
			check[i]++;
			return i;
		}
	}
	return -1;
}

void product_information(int n)
{
	double discounted_price;
	printf("product: %s\n", goods_base[n]);
	printf("cost: %lf\n", cost_base[n]);
	printf("sale: %lf\n", sale_base[n]);
	discounted_price = cost_base[n] * sale_base[n] / 100.0;
	printf("cost: %lf\n", discounted_price);
	printf("count: %d\n", check[n]);
	final_price += discounted_price;
}

void final_check()
{
	int i = 0;
	printf("....CHECK....\n");
	for (; i < N; i++)
	{
		if (check[i] != 0)
			product_information(i);
	}
	printf("%f\n", final_price);
}