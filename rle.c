#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	/*These are equivalent 
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	    return 1;
	else
	    return 0;*/
}

//btw the Printable characters range inclusive are (c >= 32 && c <= 126)

 
int valid_string(char *src)
{
    int i = 0, rln;
    while (src[i])
    {
        if (!check(src[i]))
            return 0; 
        rln = 1;
        while (src[i + 1] && src[i] == src[i + 1])
        {
            rln++;
            i++;
        }
        if (rln > 9)
            return 0;
        i++;
    }
    return 1; 
} 
void	encode(char *src)
{

	int i;
	i = 0;

	if (!valid_string(src))
	return;
	// Since the function is void and not int, the only way to exit is to use return without 0, 
	// which has the same effect.

	int rln;
	while (src[i])
	{
		rln = 1;
		while(src[i+1] && src[i] == src[i+1])
			{
				rln++;
				i++;
			}
		if (rln > 1)
		{
		ft_putchar(rln + '0');
		ft_putchar(src[i]);
		}
		else
		{		
		ft_putchar(src[i]);
		}
		i++;
	}
	write(1,"/n", 1);
}

int main(void)
{
	char str[] = "ssse5abc\7defddddfffd3e  e5";
	encode(str);
	return(0);
}
