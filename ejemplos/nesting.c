int main()
{
	int a = 0;
	int b;

	while(a != 3) {
		in(&b);
		if(b != 0) {
			out(b);
		}
		a++;
	}
}
