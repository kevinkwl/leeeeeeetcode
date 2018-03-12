// 12ms 100%

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct _cell {
    int r, c;
    int h;
} cell_t;
typedef struct _cell_queue {
    cell_t cells[120*120];
    int size;
} queue_t;

void swap(cell_t *cells, int i, int j)
{
    int tr = cells[i].r, tc = cells[i].c, th = cells[i].h;
    cells[i].r = cells[j].r;
    cells[i].c = cells[j].c;
    cells[i].h = cells[j].h;
    
    cells[j].r = tr;
    cells[j].c = tc;
    cells[j].h = th;
}
void push(queue_t *q, int r, int c, int h)
{
    int cur = q->size++;
    cell_t *cells = q->cells;
    cells[cur].r = r;
    cells[cur].c = c;
    cells[cur].h = h;
    
    int prt;
    while (cur > 0) {
        prt = (cur-1)/2;
        if (cells[prt].h < cells[cur].h)   break;
        swap(cells, prt, cur);
        cur = prt;
    }
}

int pop(queue_t *q, cell_t *pcell)
{
    if (q->size < 1)    return 0;
    cell_t *cells = q->cells;
    pcell->r = cells[0].r;
    pcell->c = cells[0].c;
    pcell->h = cells[0].h;
    
    swap(cells, 0, q->size-1);
    q->size--;
    int cur = 0, down;
    int lc, rc;
    while (1) {
        down = cur;
        lc = 2 * cur + 1;
        rc = lc + 1;
        if (lc < q->size && cells[lc].h < cells[cur].h)   down = lc;
        if (rc < q->size && cells[rc].h < cells[down].h ) down = rc;
        if (down == cur)    break;
        swap(cells, cur, down);
        cur = down;
    }
    return 1;
}

int trapRainWater(int** heightMap, int heightMapRowSize, int heightMapColSize) 
{
    queue_t q;
    q.size = 0;
    cell_t cur;
    int visited[120][120];
    memset(visited, 0, sizeof(visited));
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    int rm = heightMapRowSize, cm = heightMapColSize;
    // init the queue with boundary
    for (int r = 0; r < rm; r++) {
        if (!visited[r][0]) {
            push(&q, r, 0, heightMap[r][0]);
            visited[r][0] = 1;
        }
        if (!visited[r][cm-1]) {
            push(&q, r, cm-1, heightMap[r][cm-1]);
            visited[r][cm-1] = 1;
        }
    }
    for (int c = 0; c < cm; c++) {
        if (!visited[0][c]) {
            push(&q, 0, c, heightMap[0][c]);
            visited[0][c] = 1;
        }
        if (!visited[rm-1][c]) {
            push(&q, rm-1, c, heightMap[rm-1][c]);
            visited[rm-1][c] = 1;
        }
    }
    int newr, newc;
    int water = 0, level = 0;
    while (pop(&q, &cur)) {
        level = max(level, cur.h);
        for (int i = 0; i < 4; i++) {
            newr = cur.r + dr[i];
            newc = cur.c + dc[i];
            if (newr >= 0 && newr < rm && newc >= 0 && newc < cm)
                if (!visited[newr][newc]) {
                    int tw;
                    tw = max(0, level - heightMap[newr][newc]);
                    water += tw;
                    visited[newr][newc] = 1;
                    push(&q, newr, newc, heightMap[newr][newc]);
                }
        }
    }
    return water;
}
