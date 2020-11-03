#include <vector>
#include <functional> 
#include <stdio.h>
#include <string.h> 
#include <sstream>
#include <fstream>
#include "word.h"

int main()
{
    base();

    /*char a[100] = "test";
    
    scanf("%s", sen);

    if (strcmp(sen,a) == 0)
        printf("o");
    else
        printf("x");*/
    while (true)
    {

        printf("찾을 단어를 검색하십시오\n");
        scanf("%s", sen);

        while (sen[num] != NULL)
        {
            len++;
            num++;
        }

        for (int i = 0; i < len; i++)
        {
            if (sen[i] <= 90 && sen[i] >= 65)
                sen[i] = tolower(sen[i]);

            if (sen[i] < 65 || 90 < sen[i] < 97 || sen[i] > 122)
            {
                err = 1;
                break;
            }


        }
        if (err == 1)
        {
            reset();
            continue;
        }
        //printf("%s\n", sen);

        s_range = Range[(int)sen[0] - first_Ac];
        printf("%d\n", s_range.first);

        for (int i = s_range.first - 1; i <= s_range.last - 1; i++)
            if (word[i].len == len)
                _word.push_back(word[i]);


        first = 0;
        last = _word.size() - 1;
        
        for (int i = first; i <= last ; i++)
            printf("%s\n", _word[i].sen);

        printf("%d\n", _word.size());

        while (true)
        {
            /*
            if (sen[len - 1] == _word[mid].sen[len - 1])
                break;
                */
            mid = (first + last) / 2;
            _mid = mid + 1;

            if ((int)sen[1 + ad] < (int)_word[mid].sen[1 + ad])
                last = mid;
            else if ((int)sen[1 + ad] > (int)_word[mid].sen[1 + ad])
                first = mid;
            else if ((int)sen[1 + ad] == (int)_word[mid].sen[1 + ad])
            {
                if (strcmp(sen, _word[mid].sen) == 0)
                {   
                    t_word = _word[mid];
                    break;
                }
                else if (strcmp(sen, _word[_mid].sen) == 0)
                {
                    mid = _mid;
                    break;
                }
                    
                f_num = mid - 2;
                l_num = mid + 2;

                while (true)
                {
                    if ((int)sen[1 + ad] == (int)_word[f_num].sen[1 + ad])
                    {
                        f_num = f_num - 2;
                        continue;
                    }

                    f_num = f_num + 1;
                    if ((int)sen[1 + ad] == (int)_word[f_num].sen[1 + ad])
                        first = f_num;
                    else
                        first = f_num + 1;
                    break;
                }

                while (true)
                {
                    if ((int)sen[1 + ad] == (int)_word[l_num].sen[1 + ad])
                    {
                        l_num = l_num + 2;
                        continue;
                    }

                    l_num = l_num - 1;
                    if ((int)sen[1 + ad] == (int)_word[l_num].sen[1 + ad])
                        last = l_num;
                    else
                        last = l_num - 1;
                    break;
                }

                if (strcmp(sen, _word[first].sen) == 0)
                {
                    t_word = _word[first];
                    break;
                }
                if (strcmp(sen, _word[last].sen) == 0)
                {
                    t_word = _word[last];
                    break;
                }
                ad++;
            }
        }

        printf("%s\n\n", t_word.mean);
        //printf("%d", len);

        continue;
    }
}
      

