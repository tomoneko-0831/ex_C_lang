#include <stdio.h>
#include <time.h>

//textの文字列長（適当に決める）
#define TEXT_LEN 100
//patternの文字列長（適当に決める）
#define PAT_LEN 20

#define True 1
#define False 0

int str_search (char text[], char pattern[]) {
    // char text[]="探している文字列があるかもしれないテキスト;
    // char pattern[]="探している文字列（単語）";
    int i = 0;
    while (1) {
        int j = 0;
        while (1) {
            // テキストの最後に到達したとき
            if (text[i+j] == '\0') {
                return False;
            }
            // 探しているパターンと一致したとき
            if (pattern[j] == '\0') {
                return True;
            }
            // 探すパターンと一致しなかったとき
            if (text[i+j] != pattern[j]) {
                break;
            }
            j++;
        }
        i++;
    }
}

int main() {
    int start, end;
    double cputime;

    char text[TEXT_LEN+1];
    // ここでtext[]にaaa...aaという文字列を入れる
    for (int i = 0; i < TEXT_LEN; i++) {
        text[i] = 'a';
    }

    // ここでpattern[]に何かを入れる
    char pattern[PAT_LEN+1] = "sldkfjgnvmhjgntmyjhk";

    // 最後に’¥0’を忘れないように
    text[TEXT_LEN] = '\0';
    pattern[PAT_LEN] = '\0';

    //測定開始時刻
    start = clock();
    for(int i=0; i<1000; i++){
        str_search(text, pattern);
    }

    //測定終了時刻
    end = clock();

    //測定時間の計算と表示（CPU時間で換算）
    //ここは普通，CLOCK_PER_SECで割る（今回は知らん）
    cputime = (double)(end-start)/1000.0;
    printf("%f\n", cputime);
    return 0;
}
