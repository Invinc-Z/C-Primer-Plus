#include <stdio.h>
#include <string.h>
#define MAX_PLAYERS 19
#define NAME_LEN 20

/**
 * 一个文本文件中保存着一个垒球队的信息。每行数据都是这样排列：
 * 4 Jessie Joybat 5 2 1 1
 * 第1项是球员号，为方便起见，其范围是0～18。第2项是球员的名。第3项是球员的姓。名和姓都是一个单词。第4项是官方统计的球员上场次数。
 * 接着3项分别是击中数、走垒数和打点（RBI）。文件可能包含多场比赛的数据，所以同一位球员可能有多行数据，而且同一位球员的多行数据之间可能有其他球员的数据。
 * 编写一个程序，把数据储存到一个结构数组中。该结构中的成员要分别表示球员的名、姓、上场次数、击中数、走垒数、打点和安打率（稍后计算）。
 * 可以使用球员号作为数组的索引。该程序要读到文件结尾，并统计每位球员的各项累计总和。世界棒球统计与之相关。
 * 例如，一次走垒和触垒中的失误不计入上场次数，但是可能产生一个RBI。但是该程序要做的是像下面描述的一样读取和处理数据文件，不会关心数据的实际含义。
 * 要实现这些功能，最简单的方法是把结构的内容都初始化为零，把文件中的数据读入临时变量中，然后将其加入相应的结构中。
 * 程序读完文件后，应计算每位球员的安打率，并把计算结果储存到结构的相应成员中。计算安打率是用球员的累计击中数除以上场累计次数。这是一个浮点数计算。
 * 最后，程序结合整个球队的统计数据，一行显示一位球员的累计数据。
 */

struct Player {
    int id; // 球员号
    char first_name[NAME_LEN]; // 名
    char last_name[NAME_LEN]; // 姓
    int games_played; // 上场次数
    int hits; // 击中数
    int walks; // 走垒数
    int rbi; // 打点
    float batting_average; // 安打率
};

int main()
{
    struct Player team[MAX_PLAYERS] = { 0 }; // 初始化球队数组
    FILE* file = fopen("team.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return -1;
    }
    int id, games_played, hits, walks, rbi;
    char first_name[NAME_LEN], last_name[NAME_LEN];
    while (fscanf(file, "%d %s %s %d %d %d %d", &id, first_name, last_name, &games_played, &hits, &walks, &rbi) == 7) {
        if (id < 0 || id >= MAX_PLAYERS) {
            printf("Invalid player ID: %d\n", id);
            continue;
        }
        struct Player* player = &team[id];
        player->id = id;
        strcpy(player->first_name, first_name);
        strcpy(player->last_name, last_name);
        player->games_played += games_played;
        player->hits += hits;
        player->walks += walks;
        player->rbi += rbi;
    }
    fclose(file);
    printf("Player Statistics:\n");
    printf("%-5s %-15s %-15s %-15s %-10s %-10s %-10s %-10s\n", "ID", "First Name", "Last Name", "Games Played", "Hits", "Walks", "RBI", "Batting Avg");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (team[i].games_played > 0) {
            team[i].batting_average = (float)team[i].hits / team[i].games_played; // 计算安打率
            printf("%-5d %-15s %-15s %-15d %-10d %-10d %-10d %.3f\n",
                   team[i].id,
                   team[i].first_name,
                   team[i].last_name,
                   team[i].games_played,
                   team[i].hits,
                   team[i].walks,
                   team[i].rbi,
                   team[i].batting_average);
        }
    }

    return 0;
}
