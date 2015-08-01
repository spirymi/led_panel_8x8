// 2-dimensional array of row pin numbers:
const int row[8] = {
	4, 9, 19, 7, 3, 18, 2, 16 };

// 2-dimensional array of column pin numbers:
const int col[8] = {
	8, 14, 15, 5, 17, 6, 10, 11 };

int v = 3;
int dms = 400;

boolean A[8][8] =
{ 0, 0, 1, 1, 1, 1, 0, 0,
0, 1, 0, 0, 0, 0, 1, 0,
0, 1, 0, 0, 0, 0, 1, 0,
0, 1, 0, 0, 0, 0, 1, 0,
0, 1, 1, 1, 1, 1, 1, 0,
0, 1, 0, 0, 0, 0, 1, 0,
0, 1, 0, 0, 0, 0, 1, 0,
0, 1, 0, 0, 0, 0, 1, 0 };

void setup()
{
	for (int i = 0; i<8; i++)
	{
		pinMode(row[i], OUTPUT);
		pinMode(col[i], OUTPUT);
	}
	for (int i = 0; i<8; i++)
	{
		digitalWrite(row[i], HIGH);
	}
}

void loop()
{
	paint(A);

	//scroll(A);
}

void paint(boolean screen[8][8])
{
	int i, j;
	for (i = 0; i<8; i++)
		for (j = 0; j<8; j++)
		{
			if (screen[i][j] == 1)
			{
				digitalWrite(row[i], LOW);
				digitalWrite(col[j], HIGH);
				delayMicroseconds(dms);
				digitalWrite(row[i], HIGH);
				digitalWrite(col[j], LOW);
			}
			else
			{
				digitalWrite(row[i], HIGH);
				digitalWrite(col[j], LOW);
				delayMicroseconds(dms);
				digitalWrite(row[i], HIGH);
				digitalWrite(col[j], LOW);
			}
		}
}

void scroll(boolean screen[8][8])
{
	boolean buf[8][1];
	for (int i = 0; i<8; i++)
	{
		buf[i][0] = screen[i][0];
	}
	for (int i = 0; i<8; i++)
		for (int j = 0; j<8; j++)
		{
			screen[i][j] = screen[i][j + 1];
		}
	for (int i = 0; i<8; i++)
	{
		screen[i][8 - 1] = buf[i][0];
	}
}