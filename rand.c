//
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//#include <stdio.h>
//
//#define MAS 500
//#define MAXP 1000000
//#define MINP -1000000
//
//int     main () {
//	int i, j;
//	int arr[MAS];
//	int buf;
//	int l;
//
//	j = 0;
//	l = 0;
//	i = 0;
//	buf = 0;
//	srand(time(NULL));
//	while (i < MAS) {
//		buf = MINP + rand() % (MAXP - MINP);
//		arr[i] = buf;
//		++i;
//	}
//	i = 0;
//	srand(time(NULL));
//	while (i < MAS)
//	{
//		j = i + 1;
//		while (j < MAS)
//		{
//			if (arr[i] == arr[j])
//			{
//				arr[j] = MINP + rand() % (MAXP - MINP);
//				l = 1;
//				break ;
//			}
//			++j;
//		}
//		if (l == 1)
//		{
//			i = 0;
//			l = 0;
//			continue ;
//		}
//		++i;
//	}
//	i = 0;
//	while (i < MAS)
//		printf("%d ", arr[i++]);
//}