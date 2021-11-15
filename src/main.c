/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chemelin <chemelin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 08:03:01 by chemelin          #+#    #+#             */
/*   Updated: 2020/05/22 18:31:27 by chemelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

int				ft_printf(const char *str, ...);

void 			ft_putstr_fd(int fd, char *str)
{
	int i;

	while (i < ft_strlen(str))
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int main()
{
	printf("\n--------------General check-------------\n");
	int a1, b1;
	a1 = ft_printf("Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And now unsigned: |%u|\n", "abra", 'e', 56, -43);
	b1 = printf("Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And now unsigned: |%u|\n", "abra", 'e', 56, -43);
	printf("%d %d\n", a1, b1);
	a1 = ft_printf("and now heximal: |%8x|, |%X|\n", 5554645, -123);
	b1 = printf("and now heximal: |%8x|, |%X|\n", 5554645, -123);
	printf("%d %d\n", a1, b1);
	char *ptr = NULL;
	printf("|%p %s|\n", NULL, ptr);
	ft_printf("|%p %s|\n", NULL, ptr);

	printf("\n--------------Check for i-------------\n");
	ft_printf("|%i|\n",   10);
	printf("|%i|\n",  10);
	ft_printf("|%*.*i|\n", 8, 5, 15 );
	printf("|%*.*i|\n", 8, 5, 15 );
	ft_printf("|%*.*i|\n", 8, 5, 152352352 );
	printf("|%*.*i|\n", 8, 5, 152352352 );
	ft_printf("|%0*i|\n", 18, 152352352 );
	printf("|%0*i|\n", 18, 152352352 );
	ft_printf("|%*.*i|\n", 18, 10, 152352352 );
	printf("|%*.*i|\n", 18, 10, 152352352 );
	ft_printf("|%-*.*i|\n", 18, 10, 152352352 );
	printf("|%-*.*i|\n", 18, 10, 152352352 );
	ft_printf("|%*.*i|\n", 18, 15, -152352352 );
	printf("|%*.*i|\n", 18, 15, -152352352 );
	ft_printf("|%*.*i|\n", 18, 10, 152352352 );
	printf("|%*.*i|\n", 18, 10, 152352352 );
	ft_printf("|%*.*i|\n", 18, 15, -152352352 );
	printf("|%*.*i|\n", 18, 15, -152352352 );
	ft_printf("|%-*.*i|\n", 3, 15, -152352352 );
	printf("|%-*.*i|\n", 3, 15, -152352352 );
	ft_printf("|%0*.*i|\n", 18, 4, 152352352 );
	printf("|%0*.*i|\n", 18, 4, 152352352 );
	printf("\n--------------Check for negative width and accuracy: i-------------\n");
	ft_printf("|%-*.*i|\n", -10, -5, 10);
	printf("|%-*.*i|\n", -10, -5, 10);
	ft_printf("|%*.*i|\n", -8, -5, 15 );
	printf("|%*.*i|\n", -8, -5, 15 );
	ft_printf("|%*.*i|\n", -8, -5, 152352352 );
	printf("|%*.*i|\n", -8, -5, 152352352 );
	ft_printf("|%0*i|\n", -18, 152352352 );
	printf("|%0*i|\n", -18, 152352352 );
	ft_printf("|%*.*i|\n", -18, -10, 152352352 );
	printf("|%*.*i|\n", -18, -10, 152352352 );
	ft_printf("|%-*.*i|\n", -18, -10, 152352352 );
	printf("|%-*.*i|\n", -18, -10, 152352352 );
	ft_printf("|%*.*i|\n", -18, -15, -152352352 );
	printf("|%*.*i|\n", -18, -15, -152352352 );
	ft_printf("|%*.*i|\n", -18, 10, 152352352 );
	printf("|%*.*i|\n", -18, 10, 152352352 );
	ft_printf("|%*.*i|\n", 18, -15, -152352352 );
	printf("|%*.*i|\n", 18, -15, -152352352 );
	ft_printf("|%-*.*i|\n", -3, -15, -152352352 );
	printf("|%-*.*i|\n", -3, -15, -152352352 );
	ft_printf("|%0*.*i|\n", -18, -4, 152352352 );
	printf("|%0*.*i|\n", -18, -4, 152352352 );

	printf("\n--------------Check for d-------------\n");
	ft_printf("|%-*.*d|\n", 10, 5, 10);
	printf("|%-*.*d|\n", 10, 5, 10);
	ft_printf("|%*.*d|\n", 8, 5, 15 );
	printf("|%*.*d|\n", 8, 5, 15 );
	ft_printf("|%*.*d|\n", 8, 5, 152352352 );
	printf("|%*.*d|\n", 8, 5, 152352352 );
	ft_printf("|%0*d|\n", 18, 152352352 );
	printf("|%0*d|\n", 18, 152352352 );
	ft_printf("|%*.*d|\n", 18, 10, 152352352 );
	printf("|%*.*d|\n", 18, 10, 152352352 );
	ft_printf("|%-*.*d|\n", 18, 10, 152352352 );
	printf("|%-*.*d|\n", 18, 10, 152352352 );
	ft_printf("|%*.*d|\n", 18, 15, -152352352 );
	printf("|%*.*d|\n", 18, 15, -152352352 );
	ft_printf("|%*.*d|\n", 18, 10, 152352352 );
	printf("|%*.*d|\n", 18, 10, 152352352 );
	ft_printf("|%*.*d|\n", 18, 15, -152352352 );
	printf("|%*.*d|\n", 18, 15, -152352352 );
	ft_printf("|%-*.*d|\n", 3, 15, -152352352 );
	printf("|%-*.*d|\n", 3, 15, -152352352 );
	ft_printf("|%-*.*d|\n", 15, 3, -152352352 );
	printf("|%-*.*d|\n", 15, 3, -152352352 );
	ft_printf("|%0*.*d|\n", 18, 4, 152352352 );
	printf("|%0*.*d|\n", 18, 4, 152352352 );
	printf("\n--------------Tests with negative width and accuracy for d-------------\n");
	ft_printf("|%-*.*d|\n", -10, -5, 10);
	printf("|%-*.*d|\n", -10, -5, 10);
	ft_printf("|%*.*d|\n", -8, 5, 15 );
	printf("|%*.*d|\n", -8, 5, 15 );
	ft_printf("|%*.*d|\n", 8, -5, 152352352 );
	printf("|%*.*d|\n", 8, -5, 152352352 );
	ft_printf("|%0*d|\n", -18, 152352352 );
	printf("|%0*d|\n", -18, 152352352 );
	ft_printf("|%*.*d|\n", -18, 10, 152352352 );
	printf("|%*.*d|\n", -18, 10, 152352352 );
	ft_printf("|%-*.*d|\n", 18, -10, 152352352 );
	printf("|%-*.*d|\n", 18, -10, 152352352 );
	ft_printf("|%*.*d|\n", -18, -15, -152352352 );
	printf("|%*.*d|\n", -18, -15, -152352352 );
	ft_printf("|%*.*d|\n", 18, -10, 152352352 );
	printf("|%*.*d|\n", 18, -10, 152352352 );
	ft_printf("|%*.*d|\n", -18, 15, -152352352 );
	printf("|%*.*d|\n", -18, 15, -152352352 );
	ft_printf("|%-*.*d|\n", 3, -15, -152352352 );
	printf("|%-*.*d|\n", 3, -15, -152352352 );
	ft_printf("|%-*.*d|\n", -15, 3, -152352352 );
	printf("|%-*.*d|\n", -15, 3, -152352352 );
	printf("efvevf\n");
	ft_printf("|%0*.*d|\n", -18, -4, 152352352 );
	printf("|%0*.*d|\n", -18, -4, 152352352 );
	ft_printf("|%0*.*d|\n", -18, 10, 152352352 );
	printf("|%0*.*d|\n", -18, 10, 152352352 );
	ft_printf("|%0*.*d|\n", 18, -15, -152352352 );
	printf("|%0*.*d|\n", 18, -15, -152352352 );
	ft_printf("|%-*.*d|\n", -3, 15, -152352352 );
	printf("|%-*.*d|\n", -3, 15, -152352352 );
	ft_printf("|%0*.*d|\n", 18, -4, 152352352 );
	printf("|%0*.*d|\n", 18, -4, 152352352 );
	printf("\n--------------Other tests for d-------------\n");
	ft_printf("|%.0d|\n", 0);
	printf("|%.0d|\n", 0);
	ft_printf("|%.d|\n", 0);
	printf("|%.d|\n", 0);
	ft_printf("|%5.d|\n", 0);
	printf("|%5.d|\n", 0);
	ft_printf("|%5.0d|\n", 0);
	printf("|%5.0d|\n", 0);
	ft_printf("|%-5.d|\n", 0);
	printf("|%-5.d|\n", 0);

	printf("\n--------------Check for u-------------\n");
	ft_printf("|%-*.*u|\n", 10, 5, 10);
	printf("|%-*.*u|\n", 10, 5, 10);
	ft_printf("|%*.*u|\n", 8, 5, 15 );
	printf("|%*.*u|\n", 8, 5, 15 );
	ft_printf("|%*.*u|\n", 8, 5, 152352352 );
	printf("|%*.*u|\n", 8, 5, 152352352 );
	ft_printf("|%0*u|\n", 18, 152352352 );
	printf("|%0*u|\n", 18, 152352352 );
	ft_printf("|%*.*u|\n", 18, 10, 152352352 );
	printf("|%*.*u|\n", 18, 10, 152352352 );
	ft_printf("|%-*.*u|\n", 18, 10, 152352352 );
	printf("|%-*.*u|\n", 18, 10, 152352352 );
	ft_printf("|%*.*u|\n", 18, 15, -152352352 );
	printf("|%*.*u|\n", 18, 15, -152352352 );
	ft_printf("|%*.*u|\n", 18, 10, 152352352 );
	printf("|%*.*u|\n", 18, 10, 152352352 );
	ft_printf("|%*.*u|\n", 18, 15, -152352352 );
	printf("|%*.*u|\n", 18, 15, -152352352 );
	ft_printf("|%-*.*u|\n", 3, 15, -152352352 );
	printf("|%-*.*u|\n", 3, 15, -152352352 );
	ft_printf("|%0*.*u|\n", 18, 4, 152352352 );
	printf("|%0*.*u|\n", 18, 4, 152352352 );
	printf("|%020.18u|\n", -345);
	ft_printf("|%020.18u|\n", -345);
	printf("|%-20.18u|\n", -345);
	ft_printf("|%-20.18u|\n", -345);
	printf("|%-20.*u|\n", -18, -345);
	ft_printf("|%-20.*u|\n", -18, -345);

	printf("\n--------------Check with negative width and accuracy for u-------------\n");
	ft_printf("|%*.*u|\n", -18, -10, 152352352 );
	printf("|%*.*u|\n", -18, -10, 152352352 );
	ft_printf("|%-*.*u|\n", 18, -10, 152352352 );
	printf("|%-*.*u|\n", 18, -10, 152352352 );
	ft_printf("|%*.*u|\n", -18, 15, -152352352 );
	printf("|%*.*u|\n", -18, 15, -152352352 );
	ft_printf("|%0*.*u|\n", -18, 10, 152352352 );
	printf("|%0*.*u|\n", -18, 10, 152352352 );
	ft_printf("|%0*.*u|\n", 18, -15, -152352352 );
	printf("|%0*.*u|\n", 18, -15, -152352352 );
	ft_printf("|%-*.*u|\n", -3, 15, -152352352 );
	printf("|%-*.*u|\n", -3, 15, -152352352 );
	ft_printf("|%0*.*u|\n", 18, -4, 152352352 );
	printf("|%0*.*u|\n", 18, -4, 152352352 );
	ft_printf("|%*.*u|\n", -18, -10, 0 );
	printf("|%*.*u|\n", -18, -10, 0 );
	ft_printf("|%-*.*u|\n", 18, -10, 0 );
	printf("|%-*.*u|\n", 18, -10, 0 );
	ft_printf("|%*.*u|\n", -18, 15, -0 );
	printf("|%*.*u|\n", -18, 15, -0 );
	ft_printf("|%0*.*u|\n", -18, 10, 0 );
	printf("|%0*.*u|\n", -18, 10, 0 );
	ft_printf("|%0*.*u|\n", 18, -15, -0 );
	printf("|%0*.*u|\n", 18, -15, -0 );
	ft_printf("|%-*.*u|\n", -3, 15, -0 );
	printf("|%-*.*u|\n", -3, 15, -0 );
	ft_printf("|%0*.*u|\n", 18, -4, 0 );
	printf("|%0*.*u|\n", 18, -4, 0 );

	printf("\n--------------Check for x-------------\n");
	ft_printf("|%-*.*x|\n", 10, 5, 10);
	printf("|%-*.*x|\n", 10, 5, 10);
	ft_printf("|%*.*x|\n", 8, 5, 15 );
	printf("|%*.*x|\n", 8, 5, 15 );
	ft_printf("|%*.*x|\n", 8, 5, 152352352 );
	printf("|%*.*x|\n", 8, 5, 152352352 );
	ft_printf("|%0*x|\n", 18, 152352352 );
	printf("|%0*x|\n", 18, 152352352 );
	ft_printf("|%-*.*x|\n", 10, 0, 0);
	printf("|%-*.*x|\n", 10, 0, 0);
	ft_printf("|%*.*x|\n", 8, 0, 0 );
	printf("|%*.*x|\n", 8, 0, 0 );
	ft_printf("|%*.*x|\n", 8, 5, 0 );
	printf("|%*.*x|\n", 8, 5, 0 );
	ft_printf("|%0*x|\n", 18, 0 );
	printf("|%0*x|\n", 18, 0 );
	ft_printf("|%*.*x|\n", 18, 10, 152352352 );
	printf("|%*.*x|\n", 18, 10, 152352352 );
	ft_printf("|%-*.*x|\n", 18, 10, 152352352 );
	printf("|%-*.*x|\n", 18, 10, 152352352 );
	ft_printf("|%*.*x|\n", 18, 15, -152352352 );
	printf("|%*.*x|\n", 18, 15, -152352352 );
	ft_printf("|%*.*x|\n", 18, 10, 152352352 );
	printf("|%*.*x|\n", 18, 10, 152352352 );
	ft_printf("|%*.*x|\n", 18, 15, -152352352 );
	printf("|%*.*x|\n", 18, 15, -152352352 );
	ft_printf("|%-*.*x|\n", 3, 15, -152352352 );
	printf("|%-*.*x|\n", 3, 15, -152352352 );
	ft_printf("|%0*.*x|\n", 18, 4, 152352352 );
	printf("|%0*.*x|\n", 18, 4, 152352352 );

	printf("\n--------------Check with negative width and accuracy for x-------------\n");
	ft_printf("|%*.*x|\n", -18, -10, 152352352 );
	printf("|%*.*x|\n", -18, -10, 152352352 );
	ft_printf("|%-*.*x|\n", 18, -10, 152352352 );
	printf("|%-*.*x|\n", 18, -10, 152352352 );
	ft_printf("|%*.*x|\n", -18, 15, -152352352 );
	printf("|%*.*x|\n", -18, 15, -152352352 );
	ft_printf("|%0*.*x|\n", -18, 10, 152352352 );
	printf("|%0*.*x|\n", -18, 10, 152352352 );
	ft_printf("|%0*.*x|\n", 18, -15, -152352352 );
	printf("|%0*.*x|\n", 18, -15, -152352352 );
	ft_printf("|%-*.*x|\n", -3, 15, -152352352 );
	printf("|%-*.*x|\n", -3, 15, -152352352 );
	ft_printf("|%0*.*x|\n", 18, -4, 152352352 );
	printf("|%0*.*x|\n", 18, -4, 152352352 );
	ft_printf("|%*.*x|\n", -18, -10, 0 );
	printf("|%*.*x|\n", -18, -10, 0 );
	ft_printf("|%*.*x|\n", -18, 1, 0 );
	printf("|%*.*x|\n", -18, 1, 0 );
	ft_printf("|%*.*x|\n", -18, -1, 0 );
	printf("|%*.*x|\n", -18, -1, 0 );
	ft_printf("|%*.*x|\n", -18, 0, 0 );
	printf("|%*.*x|\n", -18, 0, 0 );
	ft_printf("|%-*.*x|\n", 18, -10, 0 );
	printf("|%-*.*x|\n", 18, -10, 0 );
	ft_printf("|%*.*x|\n", -18, 15, -0 );
	printf("|%*.*x|\n", -18, 15, -0 );
	ft_printf("|%0*.*x|\n", -18, 10, 0 );
	printf("|%0*.*x|\n", -18, 10, 0 );
	ft_printf("|%0*.*x|\n", 18, -15, -0 );
	printf("|%0*.*x|\n", 18, -15, -0 );

	ft_printf("|%-*.*x|\n", -3, 15, -0 );
	printf("|%-*.*x|\n", -3, 15, -0 );
	ft_printf("|%-*.*x|\n", -3, 15, 0 );
	printf("|%-*.*x|\n", -3, 15, 0 );
	ft_printf("|%0*.*x|\n", 18, -4, 0 );
	printf("|%0*.*x|\n", 18, -4, 0 );

	printf("\n--------------Check for X-------------\n");
	ft_printf("|%-*.*X|\n", 10, 5, 10);
	printf("|%-*.*X|\n", 10, 5, 10);
	ft_printf("|%*.*X|\n", 8, 5, 15 );
	printf("|%*.*X|\n", 8, 5, 15 );
	ft_printf("|%*.*X|\n", 8, 5, 152352352 );
	printf("|%*.*X|\n", 8, 5, 152352352 );
	ft_printf("|%0*X|\n", 18, 152352352 );
	printf("|%0*X|\n", 18, 152352352 );
	ft_printf("|%-*.*X|\n", 10, 5, 0);
	printf("|%-*.*X|\n", 10, 5, 0);
	ft_printf("|%*.*X|\n", 8, 5, 0 );
	printf("|%*.*X|\n", 8, 5, 0 );
	ft_printf("|%*.*X|\n", 8, 5, 0 );
	printf("|%*.*X|\n", 8, 5, 0 );
	ft_printf("|%0*X|\n", 18, 0 );
	printf("|%0*X|\n", 18, 0 );
	ft_printf("|%-*.*X|\n", 10, 0, 0);
	printf("|%-*.*X|\n", 10, 0, 0);
	ft_printf("|%*.*X|\n", 8, 0, 0 );
	printf("|%*.*X|\n", 8, 0, 0 );
	ft_printf("|%*.*X|\n", 8, 5, 0 );
	printf("|%*.*X|\n", 8, 5, 0 );
	ft_printf("|%0*X|\n", 18, 0 );
	printf("|%0*X|\n", 18, 0 );
	ft_printf("|%*.*X|\n", 18, 10, 152352352 );
	printf("|%*.*X|\n", 18, 10, 152352352 );
	ft_printf("|%-*.*X|\n", 18, 10, 152352352 );
	printf("|%-*.*X|\n", 18, 10, 152352352 );
	ft_printf("|%*.*X|\n", 18, 15, -152352352 );
	printf("|%*.*X|\n", 18, 15, -152352352 );
	ft_printf("|%*.*X|\n", 18, 10, 152352352 );
	printf("|%*.*X|\n", 18, 10, 152352352 );
	ft_printf("|%*.*X|\n", 18, 15, -152352352 );
	printf("|%*.*X|\n", 18, 15, -152352352 );
	ft_printf("|%-*.*X|\n", 3, 15, -152352352 );
	printf("|%-*.*X|\n", 3, 15, -152352352 );
	ft_printf("|%0*.*X|\n", 18, 4, 152352352 );
	printf("|%0*.*X|\n", 18, 4, 152352352 );

	printf("\n--------------Check for s-------------\n");
	printf("|%8s|\n", "abra");
	ft_printf("|%8s|\n", "abra");
	printf("|%-8s|\n", "abrafdefgbr");
	ft_printf("|%-8s|\n", "abrafdefgbr");
	printf("|%8s|\n", "abra");
	ft_printf("|%8s|\n", "abra");
	printf("|%8s|\n", "abrafdefgbr");
	ft_printf("|%8s|\n", "abrafdefgbr");
	ft_printf("|%*.*s|\n", 20, 5, "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%*.*s|\n", 20, 5,  "1234567890123fsfbdfbdfvbbdvbvb");
	ft_printf("|%-*.*s|\n", 20, 5, "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%-*.*s|\n", 20, 5, "1234567890123fsfbdfbdfvbbdvbvb");
	ft_printf("|%.*s|\n",  5, "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%.*s|\n",  5, "1234567890123fsfbdfbdfvbbdvbvb");
	ft_printf("|%*.s|\n", 20, "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
	ft_printf("|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
	ft_printf("|%.s|\n",  "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%.s|\n",  "1234567890123fsfbdfbdfvbbdvbvb");
	ft_printf("|%*s|\n",  40, "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%*s|\n",  40, "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
	ft_printf("|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%-*.0s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
	ft_printf("|%-*.0s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%*.1s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
	ft_printf("|%*.1s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
	ft_printf("|%-*.*s|\n", 2, 20, "1234567890123fsfbdfbdfvbbdvbvb");
	printf("|%-*.*s|\n", 2, 20, "1234567890123fsfbdfbdfvbbdvbvb");
	char *p = NULL;
	ft_printf("|%*s|\n",  40, p);
	printf("|%*s|\n",  40, p);
	ft_printf("|%*.*s|\n",  20, 2, p);
	printf("|%*.*s|\n",  20, 2, p);
	ft_printf("|%*.*s|\n",  20, 6, p);
	printf("|%*.*s|\n",  20, 6, p);
	ft_printf("|%-*s|\n",  20,  p);
	printf("|%-*s|\n",  20, p);
	ft_printf("|%-*.*s|\n",  20, 3, p);
	printf("|%-*.*s|\n",  20, 3, p);
	ft_printf("|%*s|\n",  -40, p);
	printf("|%*s|\n",  -40, p);
	ft_printf("|%*.*s|\n",  -20, -5, p);
	printf("|%*.*s|\n",  -20, -5, p);
	ft_printf("|%*.*s|\n",  -20, -6, p);
	printf("|%*.*s|\n",  -20, -6, p);
	ft_printf("|%-*s|\n",  -20,  p);
	printf("|%-*s|\n",  -20, p);
	ft_printf("|%-*.*s|\n",  -20, -5, p);
	printf("|%-*.*s|\n",  -20, -5, p);
	
	printf("\n--------------Check for p-------------\n");
	ft_printf("|%-*p|\n",  20, NULL);
	printf("|%-*p|\n",  20,  NULL);
	ft_printf("|%*p|\n",  20, NULL);
	printf("|%*p|\n",  20,  NULL);
	ft_printf("|%*p|\n",  1, NULL);
	printf("|%*p|\n",  1,  NULL);
	ft_printf("|%-*p|\n",  1, NULL);
	printf("|%-*p|\n",  1,  NULL);
	ft_printf("|%-*p|\n",  0, NULL);
	printf("|%-*p|\n",  0,  NULL);
	ft_printf("|%*p|\n",  16, NULL);
	printf("|%*p|\n",  16,  NULL);
	ft_printf("|%-*p|\n",  -20, NULL);
	printf("|%-*p|\n",  -20,  NULL);
	ft_printf("|%*p|\n",  -20, NULL);
	printf("|%*p|\n",  -20,  NULL);
	ft_printf("|%*p|\n",  -1, NULL);
	printf("|%*p|\n",  -1,  NULL);
	ft_printf("|%-*p|\n",  -1, NULL);
	printf("|%-*p|\n",  -1,  NULL);
	ft_printf("|%*p|\n",  -16, NULL);
	printf("|%*p|\n",  -16,  NULL);
	printf("\n--------------Check with . for p-------------\n");
	ft_printf("|%.p|\n", NULL);
	printf("|%.p|\n", NULL);
	ft_printf("|%.p|\n", &a1);
	printf("|%.p|\n", &a1);
	ft_printf("|%20.p|\n",NULL);
	printf("|%20.p|\n",NULL);
	ft_printf("|%20.p|\n", &a1);
	printf("|%20.p|\n", &a1);

	int a = 23;
	int *pt = &a;
	char *str = "aa";
	printf("And now address: |%p| |%p|\n", &a, str);
	ft_printf("And now address: |%p| |%p|\n", &a, str);
	ft_printf("|%-*p|\n",  20, &a);
	printf("|%-*p|\n",  20,  &a);
	ft_printf("|%*p|\n",  20, &a);
	printf("|%*p|\n",  20,  &a);
	ft_printf("|%*p|\n",  1, &a);
	printf("|%*p|\n",  1,  &a);
	ft_printf("|%-*p|\n",  1, &a);
	printf("|%-*p|\n",  1,  &a);
	ft_printf("|%-*p|\n",  0, &a);
	printf("|%-*p|\n",  0,  &a);
	ft_printf("|%*p|\n",  16, &a);
	printf("|%*p|\n",  16,  &a);
	ft_printf("|%-*p|\n",  -20, &a);
	printf("|%-*p|\n",  -20,  &a);
	ft_printf("|%*p|\n",  -20, &a);
	printf("|%*p|\n",  -20,  &a);
	ft_printf("|%*p|\n",  -1, &a);
	printf("|%*p|\n",  -1,  &a);
	ft_printf("|%-*p|\n",  -1, &a);
	printf("|%-*p|\n",  -1,  &a);
	ft_printf("|%*p|\n",  -16, &a);
	printf("|%*p|\n",  -16,  &a);
/*
	ft_printf("|%0*p|\n",  20, &a);
	printf("|%0*p|\n",  20,  &a);
	ft_printf("|%0*p|\n",  5, &a);
	printf("|%0*p|\n",  5,  &a);
	ft_printf("|%0*.30p|\n",  1, &a);
	printf("|%0*.30p|\n",  1,  &a);
	ft_printf("|%-*.5p|\n",  1, &a);
	printf("|%-*.5p|\n",  1,  &a);
	ft_printf("|%-*.5p|\n",  0, &a);
	printf("|%-*.5p|\n",  0,  &a);
	ft_printf("|%-*.8p|\n",  -1, &a);
	printf("|%-*.8p|\n",  -1,  &a);
	ft_printf("|%*.-5p|\n",  -16, &a);
	printf("|%*.-5p|\n",  -16,  &a);
*/
	ft_printf("|%*.p|\n",  16, &a);
	printf("|%*.p|\n",  16,  &a);
	ft_printf("|%-*.p|\n",  -20, &a);
	printf("|%-*.p|\n",  -20,  &a);
	ft_printf("|%*.p|\n",  -20, &a);
	printf("|%*.p|\n",  -20,  &a);
	ft_printf("|%*.p|\n",  -1, &a);
	printf("|%*.p|\n",  -1,  &a);



	printf("\n--------------Check for c-------------\n");
	ft_printf("|%*c|\n",  40, 'a');
	printf("|%*c|\n",  40, 'a');
	ft_printf("|%*c|\n",  0, 'a');
	printf("|%*c|\n",0,   'a');
	ft_printf("|%-*c|\n",0,   'a');
	printf("|%-*c|\n",0, 'a');
	ft_printf("|%-*c|\n",  40, 'a');
	printf("|%-*c|\n",  40, 'a');
	ft_printf("|%*c|\n",  5, 'a');
	printf("|%*c|\n", 5, 'a');
	ft_printf("|%-*c|\n", 5,   'a');
	printf("|%-*c|\n", 5,'a');
	ft_printf("|%-*c|\n", 1,   'a');
	printf("|%-*c|\n", 1,'a');
	ft_printf("|%-*c|\n", 0,   'a');
	printf("|%-*c|\n", 0,'a');
	printf("|%.c|\n", 'a');
	ft_printf("|%.c|\n", 'a');
	ft_printf("|%-.c|\n", 'a');
	printf("|%-.c|\n", 'a');
/*	ft_printf("|%0.c|\n", 'a');
	printf("|%0.c|\n", 'a');
	ft_printf("|%09c|\n", 'a');
	printf("|%09c|\n", 'a');
	ft_printf("|%0.*c|\n", 3,'a');
	printf("|%0.*c|\n", 3, 'a');*/
	printf("\n--------------Check with negative width for c-------------\n");
	ft_printf("|%*c|\n",  -40, 'a');
	printf("|%*c|\n",  -40, 'a');
	ft_printf("|%*c|\n",  -1, 'a');
	printf("|%*c|\n",-1,   'a');
	ft_printf("|%-*c|\n",0,   'a');
	printf("|%-*c|\n",0, 'a');
	ft_printf("|%-*c|\n",  -40, 'a');
	printf("|%-*c|\n",  -40, 'a');
	ft_printf("|%*c|\n",  -5, 'a');
	printf("|%*c|\n", -5, 'a');
	ft_printf("|%-*c|\n", -5,   'a');
	printf("|%-*c|\n", -5,'a');

	printf("\n--------------Check for empty c-------------\n");
	ft_printf("|%*c|\n",  40, '\0');
	printf("|%*c|\n",  40, '\0');
	ft_printf("|%*c|\n",  0, '\0');
	printf("|%*c|\n",0,   '\0');
	ft_printf("|%-*c|\n",0,  '\0');
	printf("|%-*c|\n",0, '\0');
	ft_printf("|%-*c|\n",  40, '\0');
	printf("|%-*c|\n",  40, '\0');
	ft_printf("|%*c|\n",  5, '\0');
	printf("|%*c|\n", 5, '\0');
	ft_printf("|%-*c|\n", 5,   '\0');
	printf("|%-*c|\n", 5,'\0');
	ft_printf("|%*c|\n",  1, '\0');
	printf("|%*c|\n", 1, '\0');
	ft_printf("|%-*c|\n", 1,   '\0');
	printf("|%-*c|\n", 1,'\0');
	printf("\n--------------Check with negative width for empty c-------------\n");
	ft_printf("|%*c|\n",  -40, '\0');
	printf("|%*c|\n",  -40, '\0');
	ft_printf("|%*c|\n",  -1, '\0');
	printf("|%*c|\n",-1,   '\0');
	ft_printf("|%-*c|\n",-1,  '\0');
	printf("|%-*c|\n",-1, '\0');
	ft_printf("|%-*c|\n",  -40, '\0');
	printf("|%-*c|\n",  -40, '\0');
	ft_printf("|%*c|\n",  -5, '\0');
	printf("|%*c|\n", -5, '\0');
	ft_printf("|%-*c|\n", -5,   '\0');
	printf("|%-*c|\n", -5,'\0');

	printf("\n--------------Check for %%-------------\n");
	ft_printf("|%5%|\n");
	printf("|%5%|\n");
	ft_printf("|%5.%|\n");
	printf("|%5.%|\n");

	ft_printf("|%-5%|\n");
	printf("|%-5%|\n");
	ft_printf("|%-5.%|\n");
	printf("|%-5.%|\n");

	ft_printf("|%*.*%|\n", 12, 15);
	printf("|%*.*%|\n", 12, 15);
	ft_printf("|%*.%|\n", 12);
	printf("|%*.%|\n", 12);

	ft_printf("|%0.*%|\n", 12);
	printf("|%0.*%|\n", 12);

	ft_printf("|%0*%|\n", 12);
	printf("|%0*%|\n", 12);
	ft_printf("|%0*.*%|\n", 12, 5);
	printf("|%0*.*%|\n", 12, 5);
	ft_printf("|%0*.*%|\n", 12, 15);
	printf("|%0*.*%|\n", 12, 15);
	ft_printf("|%0*.*%|\n", 12, 1);
	printf("|%0*.*%|\n", 12, 1);
	ft_printf("|%0*.*%|\n", 1, 5);
	printf("|%0*.*%|\n", 1, 5);
|	ft_printf("|%0*.*%|\n", 1, 1);
	printf("|%0*.*%|\n", 1, 1);
	. ft_printf("|%0*.*%|\n", 12, 0);
	printf("|%0*.*%|\n", 12, 0);

	. ft_printf("|%0*.*%|\n", 0, 10);
	printf("|%0*.*%|\n", 0, 10);
	. ft_printf("|%0*.*%|\n", 0, 0);
	printf("|%0*.*%|\n", 0, 0);

	. ft_printf("|%*.*%|\n", -12, -15);
	printf("|%*.*%|\n", -12, -15);
	.ft_printf("|%*.*%|\n", 12, -15);
	printf("|%*.*%|\n", 12, -15);
	 .ft_printf("|%*.%|\n", -12);
	printf("|%*.%|\n", -12);

	.ft_printf("|%0.*%|\n", -12);
	printf("|%0.*%|\n", -12);

	.ft_printf("|%0*%|\n", -12);
	printf("|%0*%|\n", -12);
	.ft_printf("|%0*.*%|\n", -12, -5);
	printf("|%0*.*%|\n", -12, -5);
	.ft_printf("|%0*.*%|\n", -12, -15);
	printf("|%0*.*%|\n", -12, -15);
	.ft_printf("|%0*.*%|\n", -12, -1);
	printf("|%0*.*%|\n", -12, -1);
	.ft_printf("|%0*.*%|\n", -1, -5);
	printf("|%0*.*%|\n", -1, -5);
	.ft_printf("|%0*.*%|\n", -1, -1);
	printf("|%0*.*%|\n", -1, -1);
	.ft_printf("|%0*.*%|\n", -12, 0);
	printf("|%0*.*%|\n", -12, 0);

	.ft_printf("|%0*.*%|\n", 0, -10);
	printf("|%0*.*%|\n", 0, -10);
	.ft_printf("|%0*.*%|\n", 0, 0);
	printf("|%0*.*%|\n", 0, 0);
	.ft_printf("|%-05%|\n");
	printf("|%-05%|\n");

	.a1 = printf("|%20% this is good|\n");
	.b1 = ft_printf("|%20% this is good|\n");
	.printf("%d %d\n", a1, b1);
	.a1 = printf("|%020% this is good|\n");
	.b1 = ft_printf("|%020% this is good|\n");
	.printf("%d %d\n", a1, b1);


	.printf("\n--------Other checks-------\n");
	.printf("|%32s|\n", "abc");
	.ft_printf("|%32s|\n", "abc");
	.printf("|%-32s|\n", "abc");
	.ft_printf("|%-32s|\n", "abc");
	.printf("|%16s|\n", "nark nark");
	.ft_printf("|%16s|\n", "nark nark");

	//
	//ft_printf("|%7i|\n", 33);
	//ft_printf("|%0*.*|\n", 6, 6);
	//ft_printf("|%0|\n");*/

	//ft_printf("%0-10.5d", -216);
	.int c = ft_printf("|%.03s|\n", "hello");
	.int d = printf("|%.03s|\n", "hello");
	.printf("%d = %d\n", c, d);
	.c = ft_printf("|%.3s| kushat nado |%20s|\n", "MneEEEEEEEEE", "arbuz");
	.d = printf("|%.3s| kushat nado |%20s|\n", "MneEEEEEEEEE", "arbuz");
	.printf("%d = %d\n", c, d);
	.c = ft_printf("|%08.5X|\n", 0);
	.d = printf("|%08.5X|\n", 0);
	.printf("%d = %d\n", c, d);
	.c = ft_printf("|%03.7d|\n", -2375);
	.d = printf("|%03.7d|\n", -2375);
	.printf("%d = %d\n", c, d);

    
	.printf("|%-20.18u|\n", -345);
	ft_printf("|%-20.18u|\n", -345);

	.printf("|%-20.18d|\n", -345);
	.ft_printf("|%-20.18d|\n", -345);
	.printf("|%020.2d|\n", -345);
	.ft_printf("|%020.2d|\n", -345);
	.printf("|%020d|\n", -345);
	.ft_printf("|%020d|\n", -345);

	/*a = printf("|%.*%|\n", -5);
	b = ft_printf("|%.*%|\n", -5);
	printf("%d %d\n", a, b);
	printf("|%.X|\n", 0);
	ft_printf("|%.X|\n", 0);
	ft_printf("|%.p|\n", NULL);
	ft_printf("|de %s efvef.|\n", "dfe");


	*/
	.int a2 = printf("|%%|\n");
	.int b2 = ft_printf("|%%|\n");
	.ft_printf("return for st PRINTF : %d\nreturn for my PRINTF : %d\n\n", a2, b2);

	.a2 = printf("%----24p et hello %2p %12p\n", &c, &d, NULL);
	.b2 = ft_printf("%----24p et hello %2p %12p\n", &c, &d, NULL);
	.ft_printf("return for st PRINTF : %d\nreturn for my PRINTF : %d\n\n", a2, b2);


	.a2 = printf("|test %-12i et %--2.4s %24s !|\n", 0, NULL, "coco");
	.b2 = ft_printf("|test %-12i et %--2.4s %24s !|\n", 0, NULL, "coco");
	.ft_printf("return for st PRINTF : %d\nreturn for my PRINTF : %d\n\n", a2, b2);

	printf("{%d}\n", printf("\033[1;32mTest 18 => \033[0m|%05.*d|", -15, 42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 18 => \033[0m|%05.*d|", -15, 42));
/*

TEST : %05.1u %3.4hu %-4.7U, 45, (unsigned short)-1789, 147
ft_printf  -->    45 63747 %-4.7U
ret = 14
printf     -->    45 63747 %-4.7U
ret = 18


TEST : %----24p et hello %2p %12p, &ret, &p_all_01, NULL

TEST : test %-12i et %--2.4s %24s !\n, 0, NULL, "coco"



*/





	int	*tab = malloc(sizeof(int) * 10);
	int	*tab2 = malloc(0);

	.ft_printf("--------------------%%c--------------------\n");
	.printf("01) standart PRINTF : |%c|\n", 'a');
	.ft_printf("01) my       PRINTF : |%c|\n", 'a');
	.printf("02) standart PRINTF : |%-c|\n", 'z');
	.ft_printf("02) my       PRINTF : |%-c|\n", 'z');
	.printf("03) standart PRINTF : |%-----c|\n", '!');
	.ft_printf("03) my       PRINTF : |%-----c|\n", '!');
	.printf("04) standart PRINTF : |%5c|\n", 'R');
	.ft_printf("04) my       PRINTF : |%5c|\n", 'R');
	.printf("05) standart PRINTF : |%-5c|\n", 'R');
	.ft_printf("05) my       PRINTF : |%-5c|\n", 'R');
	.printf("06) standart PRINTF : |%1c|\n", '3');
	.ft_printf("06) my       PRINTF : |%1c|\n", '3');
	.printf("07) standart PRINTF : |%c|\n", '\0');
	.ft_printf("07) my       PRINTF : |%c|\n", '\0');
	.printf("08) standart PRINTF : |%5c|\n", '\0');
	.ft_printf("08) my       PRINTF : |%5c|\n", '\0');
	.printf("09) standart PRINTF : |%-5c|\n", '\0');
	.ft_printf("09) my       PRINTF : |%-5c|\n", '\0');
	.printf("10) standart PRINTF : |%1c|\n", '\0');
	.ft_printf("10} my       PRINTF : |%1c|\n", '\0');
	.ft_printf("--------------------%%s--------------------\n");
	.printf("01) standart PRINTF : |%s|\n", "salut");
	.ft_printf("01) my       PRINTF : |%s|\n", "salut");
	.printf("02) standart PRINTF : |%-s|\n", "test");
	.ft_printf("02) my       PRINTF : |%-s|\n", "test");
	.printf("03) standart PRINTF : |%---------s|\n", "test2");
	.ft_printf("03) my       PRINTF : |%----------s|\n", "test2");
	.printf("04) standart PRINTF : |%10s|\n", "42");
	.ft_printf("04) my       PRINTF : |%10s|\n", "42");
	.printf("05) standart PRINTF : |%-10s|\n", "42");
	.ft_printf("05) my       PRINTF : |%-10s|\n", "42");
	.printf("06) standart PRINTF : |%2s|\n", "string");
	.ft_printf("06) my       PRINTF : |%2s|\n", "string");
	.printf("07) standart PRINTF : |%-2s|\n", "string");
	.ft_printf("07) my       PRINTF : |%-2s|\n", "string");
	.printf("08) standart PRINTF : |%.15s|\n", "precision");
	.ft_printf("08) my       PRINTF : |%.15s|\n", "precision");
	.printf("09) standart PRINTF : |%.4s|\n", "precision");
	.ft_printf("09) my       PRINTF : |%.4s|\n", "precision");
	.printf("10) standart PRINTF : |%.0s|\n", "precision");
	.ft_printf("10) my       PRINTF : |%.0s|\n", "precision");
	.printf("11) standart PRINTF : |%s|\n", "\0\0\0\0\0");
	.ft_printf("11) my       PRINTF : |%s|\n", "\0\0\0\0\0");
	.printf("12) standart PRINTF : |%10s|\n", "\0\0\0\0\0");
	.ft_printf("12) my       PRINTF : |%10s|\n", "\0\0\0\0\0");
	.printf("13) standart PRINTF : |%s|\n", "");
	.ft_printf("13) my       PRINTF : |%s|\n", "");
	.printf("14) standart PRINTF : |%-.2s|\n", "boom");
	.ft_printf("14) my       PRINTF : |%-.2s|\n", "boom");
	.printf("15) standart PRINTF : |%10.8s|\n", "google");
	.ft_printf("15) my       PRINTF : |%10.8s|\n", "google");
	.printf("16) standart PRINTF : |%10.2s|\n", "twitter");
	.ft_printf("16) my       PRINTF : |%10.2s|\n", "twitter");
	.printf("17) standart PRINTF : |%2.10s|\n", "samsung");
	.ft_printf("17) my       PRINTF : |%2.10s|\n", "samsung");
	.printf("18) standart PRINTF : |%2.5s|\n", "printf");
	.ft_printf("18) my       PRINTF : |%2.5s|\n", "printf");
	.printf("19) standart PRINTF : |%-10.2s|\n", "424242424242");
	.ft_printf("19) my       PRINTF : |%-10.2s|\n", "424242424242");
	.printf("20) standart PRINTF : |%1.0s|\n", "123456789");
	.ft_printf("20) my       PRINTF : |%1.0s|\n", "123456789");
	.printf("20) standart PRINTF : |%-1.0s|\n", "123456789");
	.ft_printf("20) my       PRINTF : |%-1.0s|\n", "123456789");
	printf("21) standart PRINTF : |%s|\n", NULL);
	ft_printf("21) my       PRINTF : |%s|\n", NULL);
	.printf("22) standart PRINTF : |%10s|\n", NULL);
	.ft_printf("22) my       PRINTF : |%10s|\n", NULL);
	.printf("23) standart PRINTF : |%-10s|\n", NULL);
	.ft_printf("23) my       PRINTF : |%-10s|\n", NULL);
	.printf("24) standart PRINTF : |%.1s|\n", "covid-19");
	.ft_printf("24) my       PRINTF : |%.1s|\n", "covid-19");
	.printf("25) standart PRINTF : |%10.8s|\n", NULL);
	.ft_printf("25) my       PRINTF : |%10.8s|\n", NULL);
	.printf("26) standart PRINTF : |%10.2s|\n", "covid-19");
	.ft_printf("26) my       PRINTF : |%10.2s|\n", "covid-19");
	.printf("27) standart PRINTF : |%2.10s|\n", NULL);
	.ft_printf("27) my       PRINTF : |%2.10s|\n", NULL);
	.printf("28) standart PRINTF : |%2.5s|\n", "covid-19");
	.ft_printf("28) my       PRINTF : |%2.5s|\n", "covid-19");
	.printf("29) standart PRINTF : |%-10.2s|\n", "covid-19");
	.ft_printf("29) my       PRINTF : |%-10.2s|\n", "covid-19");
	.printf("30) standart PRINTF : |%1.0s|\n", NULL);
	.ft_printf("30) my       PRINTF : |%1.0s|\n", NULL);
	.printf("31) standart PRINTF : |%-1.s|\n", NULL);
	.ft_printf("31) my       PRINTF : |%-1.s|\n", NULL);
	.ft_printf("--------------------%%p--------------------\n");
	.printf("%4.2s %-1.s\n" , "coco", NULL);
	.ft_printf("%4.2s %-1.s\n" , "coco", NULL);
	ft_printf("--------------------%%p--------------------\n");
	
	
	
	printf("01) standart PRINTF : |%p|\n", "salut");
	ft_printf("01) my       PRINTF : |%p|\n", "salut");
	.p.rintf("02) standart PRINTF : |%-p|\n", tab2);
	.ft_printf("02) my       PRINTF : |%-p|\n", tab2);
	.printf("03) standart PRINTF : |%---------p|\n", "test2");
	.ft_printf("03) my       PRINTF : |%----------p|\n", "test2");
	.printf("04) standart PRINTF : |%10p|\n", "42");
	.ft_printf("04) my       PRINTF : |%10p|\n", "42");
	.printf("05) standart PRINTF : |%-10p|\n", "42");
	.ft_printf("05) my       PRINTF : |%-10p|\n", "42");
	.printf("06) standart PRINTF : |%2p|\n", tab);
	.ft_printf("06) my       PRINTF : |%2p|\n", tab);
	.printf("07) standart PRINTF : |%-2p|\n", tab);
	.ft_printf("07) my       PRINTF : |%-2p|\n", tab);
	.printf("08) standart PRINTF : |%p|\n", "\0\0\0\0\0");
	.ft_printf("08) my       PRINTF : |%p|\n", "\0\0\0\0\0");
	.printf("09) standart PRINTF : |%20p|\n", "\0\0\0\0\0");
	.ft_printf("09) my       PRINTF : |%20p|\n", "\0\0\0\0\0");
	.printf("10) standart PRINTF : |%p|\n", "");
	.ft_printf("10) my       PRINTF : |%p|\n", "");
	.printf("11) standart PRINTF : |%p|\n", NULL);
	.ft_printf("11) my       PRINTF : |%p|\n", NULL);
	.printf("12) standart PRINTF : |%10p|\n", NULL);
	.ft_printf("12) my       PRINTF : |%10p|\n", NULL);
	.printf("13) standart PRINTF : |%-10p|\n", NULL);
	.ft_printf("13) my       PRINTF : |%-10p|\n", NULL);
	.printf("14) standart PRINTF : |%.1p|\n", NULL);
	.ft_printf("14) my       PRINTF : |%.1p|\n", NULL);
	.printf("15) standart PRINTF : |%10.2p|\n", NULL);
	.ft_printf("15) my       PRINTF : |%10.2p|\n", NULL);
	.printf("16) standart PRINTF : |%2.5p|\n", NULL);
	.ft_printf("16) my       PRINTF : |%2.5p|\n", NULL);
	.printf("17) standart PRINTF : |%-10.2p|\n", NULL);
	.ft_printf("17) my       PRINTF : |%-10.2p|\n", NULL);
	.free(tab);
	.free(tab2);
	.ft_printf("----------------%%d-%%i--------------------\n");
	printf("01) standart PRINTF : |%d|\n", 42);
	.ft_printf("01) my       PRINTF : |%d|\n", 42);
	.printf("02) standart PRINTF : |%i|\n", 42);
	.ft_printf("02) my       PRINTF : |%i|\n", 42);
	.printf("03) standart PRINTF : |%-d|\n", 42);
	.ft_printf("03) my       PRINTF : |%-d|\n", 42);
	.printf("04) standart PRINTF : |%10d|\n", 100);
	.ft_printf("04) my       PRINTF : |%10d|\n", 100);
	.printf("05) standart PRINTF : |%-10d|\n", 64);
	.ft_printf("05) my       PRINTF : |%-10d|\n", 64);
	.printf("06) standart PRINTF : |%.10d|\n", 100);
	.ft_printf("06) my       PRINTF : |%.10d|\n", 100);
	.printf("07) standart PRINTF : |%10.5d|\n", 100);
	.ft_printf("07) my       PRINTF : |%10.5d|\n", 100);
	.printf("08) standart PRINTF : |%5.10d|\n", 64);
	.ft_printf("08) my       PRINTF : |%5.10d|\n", 64);
	.printf("09) standart PRINTF : |%1.1d|\n", 16);
	.ft_printf("09) my       PRINTF : |%1.1d|\n", 16);
	.printf("10) standart PRINTF : |%d|\n", -42);
	.ft_printf("10) my       PRINTF : |%d|\n", -42);
	.printf("11) standart PRINTF : |%10d|\n", -42);
	.ft_printf("11) my       PRINTF : |%10d|\n", -42);
	.printf("12) standart PRINTF : |%.10d|\n", -42);
	.ft_printf("12) my       PRINTF : |%.10d|\n", -42);
	.printf("13) standart PRINTF : |%10.5d|\n", -16);
	.ft_printf("13) my       PRINTF : |%10.5d|\n", -16);
	.printf("14) standart PRINTF : |%5.10d|\n", -16);
	.ft_printf("14) my       PRINTF : |%5.10d|\n", -16);
	.printf("15) standart PRINTF : |%1.1d|\n", -20);
	.ft_printf("15) my       PRINTF : |%1.1d|\n", -20);
	.printf("16) standart PRINTF : |%-10d|\n", -50);
	.ft_printf("16) my       PRINTF : |%-10d|\n", -50);
	printf("17) standart PRINTF : |%2d|\n", -20);
	.ft_printf("17) my       PRINTF : |%2d|\n", -20);
	.printf("18) standart PRINTF : |%.2d|\n", -20);
	.ft_printf("18) my       PRINTF : |%.2d|\n", -20);
	.printf("19) standart PRINTF : |%2d|\n", -1);
	.ft_printf("19) my       PRINTF : |%2d|\n", -1);
	.printf("20) standart PRINTF : |%.2d|\n", -1);
	.ft_printf("20) my       PRINTF : |%.2d|\n", -1);
	.printf("21) standart PRINTF : |%-10d|\n", -80);
	.ft_printf("21) my       PRINTF : |%-10d|\n", -80);
	.printf("22) standart PRINTF : |%-.10d|\n", -80);
	.ft_printf("22) my       PRINTF : |%-.10d|\n", -80);
	.printf("23) standart PRINTF : |%06d|\n", 35);
	.ft_printf("23) my       PRINTF : |%06d|\n", 35);
	.printf("24) standart PRINTF : |%06d|\n", -35);
	.ft_printf("24) my       PRINTF : |%06d|\n", -35);
	.printf("25) standart PRINTF : |%05.3d|\n", 5);
	.ft_printf("25) my       PRINTF : |%05.3d|\n", 5);
	.printf("26) standart PRINTF : |%03.5d|\n", 5);
	.ft_printf("26) my       PRINTF : |%03.5d|\n", 5);
	.printf("27) standart PRINTF : |%05.3d|\n", -5);
	.ft_printf("27) my       PRINTF : |%05.3d|\n", -5);
	.printf("28) standart PRINTF : |%03.5d|\n", -5);
	.ft_printf("28) my       PRINTF : |%03.5d|\n", -5);
	
	.printf("31) standart PRINTF : |%.d|\n", 0);
	.ft_printf("31) my       PRINTF : |%.d|\n", 0);
	.printf("32) standart PRINTF : |%.d|\n", 100);
	.ft_printf("32) my       PRINTF : |%.d|\n", 100);
	.ft_printf("--------------------%%x--------------------\n");
	.printf("01) standart PRINTF : |%x|\n", 34);
	.ft_printf("01) my       PRINTF : |%x|\n", 34);
	.printf("02) standart PRINTF : |%x|\n", -34);
	.ft_printf("02) my       PRINTF : |%x|\n", -34);
	.printf("03) standart PRINTF : |%-x|\n", 50);
	.ft_printf("03) my       PRINTF : |%-x|\n", 50);
	.printf("04) standart PRINTF : |%10x|\n", 90);
	.ft_printf("04) my       PRINTF : |%10x|\n", 90);
	.printf("05) standart PRINTF : |%.10x|\n", 90);
	.ft_printf("05) my       PRINTF : |%.10x|\n", 90);
	.printf("06) standart PRINTF : |%15x|\n", -100);
	.ft_printf("06) my       PRINTF : |%15x|\n", -100);
	.printf("07) standart PRINTF : |%.15x|\n", -100);
	.ft_printf("07) my       PRINTF : |%.15x|\n", -100);
	.printf("08) standart PRINTF : |%10.5x|\n", 52);
	.ft_printf("08) my       PRINTF : |%10.5x|\n", 52);
	.printf("09) standart PRINTF : |%5.10x|\n", 52);
	.ft_printf("09) my       PRINTF : |%5.10x|\n", 52);
	.printf("10) standart PRINTF : |%20.15x|\n", -100000);
	.ft_printf("10) my       PRINTF : |%20.15x|\n", -100000);
	.printf("11) standart PRINTF : |%15.20x|\n", -100000);
	.ft_printf("11) my       PRINTF : |%15.20x|\n", -100000);
	.printf("12) standart PRINTF : |%-10x|\n", 144);
	.ft_printf("12) my       PRINTF : |%-10x|\n", 144);
	.printf("13) standart PRINTF : |%-.10x|\n", 144);
	.ft_printf("13) my       PRINTF : |%-.10x|\n", 144);
	.printf("14) standart PRINTF : |%-20x|\n", -20000000);
	.ft_printf("14) my       PRINTF : |%-20x|\n", -20000000);
	.printf("15) standart PRINTF : |%08x|\n", 64);
	.ft_printf("15) my       PRINTF : |%08x|\n", 64);
	.printf("16) standart PRINTF : |%03.4x|\n", 10);
	.ft_printf("16) my       PRINTF : |%03.4x|\n", 10);
	.printf("17) standart PRINTF : |%.x|\n", 0);
	.ft_printf("17) my       PRINTF : |%.x|\n", 0);
	.printf("18) standart PRINTF : |%.x|\n", 88);
	.ft_printf("18) my       PRINTF : |%.x|\n", 88);
	
	.printf("20) standart PRINTF : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);
	.ft_printf("20) my       PRINTF : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);
	.ft_printf("--------------------%%X--------------------\n");
	.printf("01) standart PRINTF : |%X|\n", 34);
	.ft_printf("01) my       PRINTF : |%X|\n", 34);
	.printf("02) standart PRINTF : |%X|\n", -34);
	.ft_printf("02) my       PRINTF : |%X|\n", -34);
	.printf("03) standart PRINTF : |%-X|\n", 50);
	.ft_printf("03) my       PRINTF : |%-X|\n", 50);
	.printf("04) standart PRINTF : |%10X|\n", 90);
	.ft_printf("04) my       PRINTF : |%10X|\n", 90);
	.printf("05) standart PRINTF : |%.10X|\n", 90);
	.ft_printf("05) my       PRINTF : |%.10X|\n", 90);
	.printf("06) standart PRINTF : |%15X|\n", -100);
	.ft_printf("06) my       PRINTF : |%15X|\n", -100);
	.printf("07) standart PRINTF : |%.15X|\n", -100);
	.ft_printf("07) my       PRINTF : |%.15X|\n", -100);
	.printf("08) standart PRINTF : |%10.5X|\n", 52);
	.ft_printf("08) my       PRINTF : |%10.5X|\n", 52);
	.printf("09) standart PRINTF : |%5.10X|\n", 52);
	.ft_printf("09) my       PRINTF : |%5.10X|\n", 52);
	.printf("10) standart PRINTF : |%20.15X|\n", -100000);
	.ft_printf("10) my       PRINTF : |%20.15X|\n", -100000);
	.printf("11) standart PRINTF : |%15.20X|\n", -100000);
	.ft_printf("11) my       PRINTF : |%15.20X|\n", -100000);
	.printf("12) standart PRINTF : |%-10X|\n", 144);
	.ft_printf("12) my       PRINTF : |%-10X|\n", 144);
	.printf("13) standart PRINTF : |%-.10X|\n", 144);
	.ft_printf("13) my       PRINTF : |%-.10X|\n", 144);
	.printf("14) standart PRINTF : |%-20X|\n", -20000000);
	.ft_printf("14) my       PRINTF : |%-20X|\n", -20000000);
	.printf("15) standart PRINTF : |%08X|\n", 64);
	.ft_printf("15) my       PRINTF : |%08X|\n", 64);
	.printf("16) standart PRINTF : |%03.4X|\n", 10);
	.ft_printf("16) my       PRINTF : |%03.4X|\n", 10);
	.printf("17) standart PRINTF : |%.X|\n", 0);
	.ft_printf("17) my       PRINTF : |%.X|\n", 0);
	.printf("18) standart PRINTF : |%.X|\n", 88);
	.ft_printf("18) my       PRINTF : |%.X|\n", 88);
	.printf("19) standart PRINTF : |%X|\n", UINT_MAX);
	.ft_printf("19) my       PRINTF : |%X|\n", UINT_MAX);
	.ft_printf("--------------------%%u--------------------\n");
	.printf("01) standart PRINTF : |%u|\n", 34);
	.ft_printf("01) my       PRINTF : |%u|\n", 34);
	.printf("02) standart PRINTF : |%u|\n", -34);
	.ft_printf("02) my       PRINTF : |%u|\n", -34);
	.printf("03) standart PRINTF : |%-u|\n", 50);
	.ft_printf("03) my       PRINTF : |%-u|\n", 50);
	.printf("04) standart PRINTF : |%10u|\n", 90);
	.ft_printf("04) my       PRINTF : |%10u|\n", 90);
	.printf("05) standart PRINTF : |%.10u|\n", 90);
	.ft_printf("05) my       PRINTF : |%.10u|\n", 90);
	.printf("06) standart PRINTF : |%15u|\n", -100);
	.ft_printf("06) my       PRINTF : |%15u|\n", -100);
	.rintf("07) standart PRINTF : |%.15u|\n", -100);
	.ft_printf("07) my       PRINTF : |%.15u|\n", -100);
	.printf("08) standart PRINTF : |%10.5u|\n", 52);
	.ft_printf("08) my       PRINTF : |%10.5u|\n", 52);
	.printf("09) standart PRINTF : |%5.10u|\n", 52);
	.ft_printf("09) my       PRINTF : |%5.10u|\n", 52);
	.printf("10) standart PRINTF : |%20.15u|\n", -100000);
	.ft_printf("10) my       PRINTF : |%20.15u|\n", -100000);
	.printf("11) standart PRINTF : |%15.20u|\n", -100000);
	.ft_printf("11) my       PRINTF : |%15.20u|\n", -100000);
	.printf("12) standart PRINTF : |%-10u|\n", 144);
	.ft_printf("12) my       PRINTF : |%-10u|\n", 144);
	.printf("13) standart PRINTF : |%-.10u|\n", 144);
	.ft_printf("13) my       PRINTF : |%-.10u|\n", 144);
	.printf("14) standart PRINTF : |%-20u|\n", -20000000);
	.ft_printf("14) my       PRINTF : |%-20u|\n", -20000000);
	.printf("15) standart PRINTF : |%08u|\n", 64);
	.ft_printf("15) my       PRINTF : |%08u|\n", 64);
	.printf("16) standart PRINTF : |%03.4u|\n", 10);
	.ft_printf("16) my       PRINTF : |%03.4u|\n", 10);
	.printf("17) standart PRINTF : |%u|\n", 0);
	.ft_printf("17) my       PRINTF : |%u|\n", 0);
	.printf("18) standart PRINTF : |%.u|\n", 0);
	.ft_printf("18) my       PRINTF : |%.u|\n", 0);
	.printf("19) standart PRINTF : |%10u|\n", 0);
	.ft_printf("19) my       PRINTF : |%10u|\n", 0);
	.printf("20) standart PRINTF : |%.u|\n", 88);
	.ft_printf("20) my       PRINTF : |%.u|\n", 88);
	.printf("21) standart PRINTF : |%u|\n", UINT_MAX);
	.ft_printf("21) my       PRINTF : |%u|\n", UINT_MAX);
	.printf("22) standart PRINTF : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 1);
	.ft_printf("22) my       PRINTF : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("--------------------%%---------------------\n");
	/*a = printf("01) standart PRINTF : |%5%|\n");
	b = ft_printf("01) my       PRINTF : |%5%|\n");
	ft_printf("return fr st PRINTF : %d\nreturn fr my PRINTF : %d\n\n", a, b);
	a = printf("02) standart PRINTF : |%-5%|\n");
	b = ft_printf("02) my       PRINTF : |%-5%|\n");
	ft_printf("return fr st PRINTF : %d\nreturn fr my PRINTF : %d\n\n", a, b);
	a = printf("03) standart PRINTF : |%.0%|\n");
	b = ft_printf("03) my       PRINTF : |%.0%|\n");
	ft_printf("return fr st PRINTF : %d\nreturn fr my PRINTF : %d\n\n", a, b);
	printf("04) standart PRINTF : |");
	a = printf("kekw %Z");
	printf("|\n");
	ft_printf("04) my       PRINTF : |");
	b = ft_printf("kekw %Z");
	ft_printf("|\n");
	ft_printf("return fr st PRINTF : %d\nreturn fr my PRINTF : %d\n\n", a, b);
	printf("05) standart PRINTF : |");
	a = printf("%");
	printf("|\n");
	ft_printf("05) my       PRINTF : |");
	b = ft_printf("%");
	ft_printf("|\n");
	ft_printf("return fr st PRINTF : %d\nreturn fr my PRINTF : %d\n\n", a, b);
	printf("06) standart PRINTF : |");
	a = printf("%%%");
	printf("|\n");
	ft_printf("06) my       PRINTF : |");
	b = ft_printf("%%%");
	ft_printf("|\n\n");
	ft_printf("return fr st PRINTF : %d\nreturn fr my PRINTF : %d\n\n", a, b);
	ft_printf("%d\n", ft_printf("%d, ", ft_printf("kekw, ")));
	ft_printf("--------------------%%kek------------------\n");*/
	.printf("01) standart PRINTF : |%.*s|\n", 5, "kekwait");
	.ft_printf("01) my       PRINTF : |%.*s|\n", 5, "kekwait");
	.printf("02) standart PRINTF : |%.*d|\n", 5, 5);
	.ft_printf("02) my       PRINTF : |%.*d|\n", 5, 5);

	.printf("03) standart PRINTF : |%.*d|\n", 5, 0);
	.ft_printf("03) my       PRINTF : |%.*d|\n", 5, 0);
	.printf("04) standart PRINTF : |%0.3s|\n", "42");
	.ft_printf("04) my       PRINTF : |%0.3s|\n\n", "42");

	.printf("01) standart PRINTF : |%.3X|\n", 17);
	.ft_printf("01) my       PRINTF : |%.3X|\n", 17);

	.ft_printf("|%s%d%p%%%i%u%x%X%c|\n","bonjour", 42, &c, 42, 42, 42, 42, 'c');
	.printf("|%s%d%p%%%i%u%x%X%c|\n","bonjour", 42, &c, 42, 42, 42, 42, 'c');

	.ft_printf("|%x|\n", -42);
	.printf("|%x|\n", -42);
	ft_printf("|%X|\n", -42);
	printf("|%X|\n", -42);

	ft_printf("|%x|\n", 4294967296);
	printf("|%x|\n", 4294967296);

	ft_printf("|%u|\n", -1);
	printf("|%u|\n", -1);
	ft_printf("|%u|\n", 4294967296);
	printf("|%u|\n", 4294967296);
}
