/***************************************************************************
 *   Copyright (C) 2008 by sh!zeeg                                         *
 *   sh!zeeg@yandex.ru                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NAME "Celebrate Checker"
#define STATE "beta"
#define VERSION 0x000203

#define CCDATA "/.cchecker/ccheck.txt"
char celebr[256];

int showmsg(char* string);

int main(int argc, char* argv[])
{
	int result=1;
	char mydate[6];
	char path_to_file[32762];
	struct tm *today;
	
	time_t now;
	time( &now );
	
	today = localtime( &now );
	
	sprintf( mydate, "%.2u.%.2u", today->tm_mday, today->tm_mon+1 );
	if( strlen( getenv("HOME")) > 1000 ) {
	  printf("ERROR: path to $(HOME)\n");
	}
	sprintf( path_to_file, "%s/%s", getenv("HOME"), CCDATA );
	FILE *myfile = fopen( path_to_file, "r" );
	

	if(myfile) {
	  while(!feof(myfile)) {
	    if(result==0) {
	      showmsg( celebr );
	      printf( celebr );
	    }

	    fgets(celebr, 255, myfile);
	    result = strncmp(celebr, mydate, 5);
	  }

	  fclose(myfile);
	} else {
	    printf("ERROR: can't open file: %s\n", CCDATA);
	}

	return 0;
}

int showmsg(char* string)
{
  char  ch, ch2;
  int	i = 1;
  int	len = strlen(string);

  for(i = 1 ;i < len; i++) {
    ch  = celebr[i-1];
    ch2 = celebr[i];
    if(ch == 92) {
      if(ch2 == 110) {
	celebr[i-1] = 0x0A;
	celebr[i]   = 0x0D;
      }
    }
  }
return 0;
}
