int main()
{
	int a = 0;
	int b = 0;

	while(a != 4) {
		out(a);
		a++;
		while(b != a) {
			out(b);
			b++;
		}
	}
}

