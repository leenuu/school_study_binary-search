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
        if (strcmp(qu, sen) == 0)
            break;

        while (sen[num] != NULL)
        {
            len++;
            num++;
        }

        for (int i = 0; i < len; i++)
        {
            if ((int)sen[i] <= 90 && (int)sen[i] >= 65)
            {
                sen[i] = tolower(sen[i]);
                continue;
            }
            if ((int)sen[i] < 65 || (90 < (int)sen[i] and (int)sen[i] < 97) || (int)sen[i] > 122)
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

        if((int)sen[0] == 121 || (int)sen[0] == 122)
            s_range = Range[(int)sen[0] - first_Ac - 1];
        else
            s_range = Range[(int)sen[0] - first_Ac];
        //printf("%d\n", s_range.first);

        for (int i = s_range.first - 1; i <= s_range.last - 1; i++)
            if (word[i].len == len)
                _word.push_back(word[i]);
        if (_word.empty())
            err_st = 200;

        first = 0;
        last = _word.size() - 1;
        /*
        for (int i = first; i <= last; i++)
            printf("%s\n", _word[i].sen);
            */
            //printf("%d\n", _word.size());

        while (true)
        {
            /*
            if (sen[len - 1] == _word[mid].sen[len - 1])
                break;
                */
            if (err_st == 200)
                break;

            mid = (first + last) / 2;


            if ((int)sen[1 + ad] < (int)_word[mid].sen[1 + ad])
            {
                last = mid;
                err_st++;
            }
            else if ((int)sen[1 + ad] > (int)_word[mid].sen[1 + ad])
            {
                first = mid;
                err_st++;
            }
            else if ((int)sen[1 + ad] == (int)_word[mid].sen[1 + ad])
            {
                if (strcmp(sen, _word[mid].sen) == 0)
                {
                    t_word = _word[mid];
                    break;
                }

                
                if (f_num >= 2)
                    f_num = mid - 2;
                else
                    f_num = mid - 1;
                

                if (l_num <= _word.size() - 3)
                    l_num = mid + 2;
                else
                    l_num = mid + 1;
                    
                //f_num = f_num - 2;
                //l_num = l_num + 2;

                while (true)
                {
                    if ((int)sen[1 + ad] == (int)_word[f_num].sen[1 + ad])
                    {
                        if (f_num >= 2)
                        {
                            f_num = f_num - 2;
                            continue;
                        }
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
                        if (l_num <= _word.size() - 3)
                        {
                            l_num = l_num + 2;
                            continue;
                        }

                    }

                    l_num = l_num - 1;
                    if ((int)sen[1 + ad] == (int)_word[l_num].sen[1 + ad])
                        last = l_num;
                    else
                        last = l_num - 1;
                    break;
                }

                
                ad++;
                err_st++;
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



        }

        if (err_st == 200)
            printf("사전에 존재하지 않는 단어입니다.\n\n");
        else
            printf("%s\n\n", t_word.mean);
        reset();
        //printf("%d", len);

        //continue;
    }
}


