class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        initDLX();
        coverExisted(board);        
        if (!solve(0))
            printf("error!\n");
        
        for (Node *s : solution) {
            int n = s->getN();
            int r = s->getRow();
            int c = s->getCol();
            board[r][c] = '0' + n;
        }
    }
    
    int solve(int k) {
        if (root.r == &root)
            return 1;
        Node *col = getColumn();
        if (col->size == 0)
            return 0;
        coverColumn(col);
        for (Node *r = col->d; r != col; r = r->d) {
            solution[k] = r;
            for (Node *j = r->r; j != r; j = j->r)
                coverColumn(j->c);
            if (solve(k + 1))
                return 1;
            for (Node *j = r->l; j != r; j = j->l)
                uncoverColumn(j->c);
        }
        uncoverColumn(col);
        return 0;
    }
    
private:
    struct Node {
        Node *u, *d, *l, *r;
        Node *c;
        int size, rid, cid;
        Node() {}
        Node(Node *uu, Node *dd, Node *ll, Node *rr, Node *cc, int size, int rid, int cid)
            : u(uu), d(dd), l(ll), r(rr), c(cc), size(size), rid(rid), cid(cid) {}
        int getRow()    { return (rid % 81) / 9;}
        int getCol()    { return (rid % 81) % 9;}
        int getN()      { return rid / 81 + 1;}
    };
#define numOfCols 81*4
#define numOfRows 81*9
    Node heads[numOfCols];      // 1 at row 1~9, 1 at col 1~9, 1 at box 1~9, 2 at row 1~9 ... ... exact 1 num at (0, 0) ...
    Node root;
    vector<Node*> solution;
    
    void initDLX() {
        root.r = &heads[0];
        for (int i = 0, j = numOfCols - 1; i < numOfCols - 1; i++, j--) {
            heads[i].r = &heads[i+1];
            heads[j].l = &heads[j-1];
            heads[i].u = &heads[i];
            heads[j].u = &heads[j];
            heads[i].d = &heads[i];
            heads[j].d = &heads[j];
            heads[i].size = heads[j].size = 0;
            heads[i].cid = i;
            heads[j].cid = j;
        }
        heads[0].l = &root;
        heads[numOfCols-1].r = &root;
        
        
        // init rows: 1 at (0, 0), 1 at (0, 1), ... ... 9 at (9, 9)
        for (int r = 0; r < numOfRows; r++) {
            // this row is for number n+1 at (i, j)
            int n = r / 81;
            int i = (r % 81) / 9;
            int j = (r % 81) % 9;
            Node *nAtRow = &heads[27*n+i];
            Node *nAtCol = &heads[27*n+9+j];
            Node *nAtBox = &heads[27*n+18+(i/3*3 + j/3)];
            Node *atIJ   = &heads[81*3+i*9+j];
            
            Node *noder = new Node(nAtRow->u, nAtRow, NULL, NULL, nAtRow, 0, r, 0);
            nAtRow->u->d = noder;
            nAtRow->u = noder;
            Node *nodec = new Node(nAtCol->u, nAtCol, noder, NULL, nAtCol, 0, r, 0);
            nAtCol->u->d = nodec;
            nAtCol->u = nodec;
            Node *nodeb = new Node(nAtBox->u, nAtBox, nodec, NULL, nAtBox, 0, r, 0);
            nAtBox->u->d = nodeb;
            nAtBox->u = nodeb;
            Node *nodeij = new Node(atIJ->u, atIJ, nodeb, noder, atIJ, 0, r, 0);
            atIJ->u->d = nodeij;
            atIJ->u = nodeij;
            
            noder->l = nodeij;
            noder->r = nodec;
            nodec->r = nodeb;
            nodeb->r = nodeij;
            
            nAtRow->size++;
            nAtCol->size++;
            nAtBox->size++;
            atIJ->size++;
        }
    }
    void coverColumn(Node *c) {
        c->r->l = c->l;
        c->l->r = c->r;
        for (Node *dc = c->d; dc != c; dc = dc->d) {
            for (Node *dcr = dc->r; dcr != dc; dcr = dcr->r) {
                dcr->d->u = dcr->u;
                dcr->u->d = dcr->d;
                dcr->c->size--;
            }
        }
    }
    void uncoverColumn(Node *c) {
        for (Node *uc = c->u; uc != c; uc = uc->u) {
            for (Node *ucl = uc->l; ucl != uc; ucl = ucl->l) {
                ucl->c->size++;
                ucl->d->u = ucl;
                ucl->u->d = ucl;
            }
        }
        c->r->l = c;
        c->l->r = c;
    }
    
    Node* getColumn() {
        int msize = root.r->size;
        Node *c = root.r;
        for (Node *j = root.r; j != &root; j = j->r)
            if (j->size < msize) {
                msize = j->size;
                c = j;
            }
        return c;
    }
    
    void coverExisted(vector<vector<char>> &board) {
        int n2s = 81;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '1';
                    int rid = n * 81 + i * 9 + j;
                    
                    Node *nAtRow = &heads[27*n+i];
                    Node *nAtCol = &heads[27*n+9+j];
                    Node *nAtBox = &heads[27*n+18+(i/3*3 + j/3)];
                    Node *atIJ   = &heads[81*3+i*9+j];
                    coverColumn(nAtRow);
                    coverColumn(nAtCol);
                    coverColumn(nAtBox);                 
                    coverColumn(atIJ); 
                    --n2s;
                }
            }
        }
        solution.resize(n2s);
    }
};
