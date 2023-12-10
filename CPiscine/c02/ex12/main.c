#include <stdio.h>
#include <stdlib.h>

extern void	*ft_print_memory(void *addr, unsigned int size);

int	main(int argc, char **argv)
{
	(void) argc;

	char c[]="Bonjour les aminches...c. est fou.tout.ce qu on peut faire avec...print_memory..cristina=thebest";
	c[20]=0x09;c[21]=0x0a;c[22]=0x09;c[24]=0x07;
	c[33]=0x09;c[38]=0x09;c[63]=0x09;
	c[64]=0x0a;c[65]=0x09;c[78]=0x0a;c[79]=0x0a;
	ft_print_memory((void *)c, atoi(argv[1]));
	return (0);
}
