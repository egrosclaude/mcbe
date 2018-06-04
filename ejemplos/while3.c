int main()
{
	int a = 0;
	int b = 0;
	int c = 1;

	while(a != 4) {
		out(a);
		a++;
		while(b != a) {
			if(b != c) {
				out(b);
			}
			b++;
		}
	}
}

