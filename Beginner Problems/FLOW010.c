#include <stdio.h>

int main (void)
{
	int cases;
	char input;
	scanf("%d", &cases);

	for (int i = 0; i < cases; i++)
	{
		scanf(" %c", &input);

		if (input == 'b' || input == 'B')
			printf("BattleShip\n");
		else if (input == 'c' || input == 'C')
			printf("Cruiser\n");
		else if (input == 'd' || input == 'D')
			printf("Destroyer\n");
		else
			printf("Frigate\n");
	}

	return 0;
}
