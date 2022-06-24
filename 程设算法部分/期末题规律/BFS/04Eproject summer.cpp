#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;
char maze[105][105];
int cnt[30];
int letter[30][3][3];
bool vst[105][105];
int cntcnt;

struct point 
{
    int x, y, steps;
};
point B;

bool check(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m) return false;
    else return true;
}

int bfs()
{
    queue <point> q;
    point cur;
    q.push(B);
    vst[B.x][B.y] = 1;
    while(!q.empty())
    {
        cntcnt++;
        cur = q.front();
        q.pop();
        if(maze[cur.x][cur.y] == 'I') return cur.steps;
        
        for(int i = 0; i < 4; ++i)
        {
            int tmpx = cur.x + dir[i][0];
            int tmpy = cur.y + dir[i][1];
            if(!check(tmpx, tmpy)) continue;
            if(maze[tmpx][tmpy] == '#') continue;
            if(vst[tmpx][tmpy]) continue;
            point tmp = cur;
            tmp.x = tmpx;
            tmp.y = tmpy;
            tmp.steps += 1;
            q.push(tmp);
            vst[tmp.x][tmp.y] = 1;
        }
        
        if(maze[cur.x][cur.y] <= 'z' && maze[cur.x][cur.y] >= 'a')
        {
            point tmp = cur;
            tmp.steps += 1;
            int l = maze[cur.x][cur.y] - 'a';
            if(cur.x == letter[l][0][0]
            && cur.y == letter[l][0][1])
            {
                tmp.x = letter[l][1][0];
                tmp.y = letter[l][1][1];
            }
            else if(cur.x == letter[l][1][0]
            && cur.y == letter[l][1][1])
            {
                tmp.x = letter[l][0][0];
                tmp.y = letter[l][0][1];
            }
            if(!vst[tmp.x][tmp.y]) 
            {
                vst[tmp.x][tmp.y] = 1;
                q.push(tmp);
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    for(int num = 1; num <= t; ++num)
    {
        cin >> n >> m;
        memset(letter, 0, sizeof(letter));
        memset(cnt, 0, sizeof(cnt));
        memset(vst, 0, sizeof(vst));
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                cin >> maze[i][j];
                if(maze[i][j] == 'B')
                {
                    B.x = i;
                    B.y = j;
                    B.steps = 0;
                }
                else if(maze[i][j] <= 'z' && maze[i][j] >= 'a')
                {
                    letter[maze[i][j] - 'a'][cnt[maze[i][j] - 'a']][0] = i;
                    letter[maze[i][j] - 'a'][cnt[maze[i][j] - 'a']][1] = j;
                    cnt[maze[i][j] - 'a']++;
                }
            }
        }
        cntcnt = 0;
        cout << "Case #" << num << ": " << bfs() << endl;
    }
    return 0;
}
