
/* qhasm: enter ge_msub */

/* qhasm: fe X1 */

/* qhasm: fe Y1 */

/* qhasm: fe Z1 */

/* qhasm: fe T1 */

/* qhasm: fe ypx2 */

/* qhasm: fe ymx2 */

/* qhasm: fe xy2d2 */

/* qhasm: fe X3 */

/* qhasm: fe Y3 */

/* qhasm: fe Z3 */

/* qhasm: fe T3 */

/* qhasm: fe YpX1 */

/* qhasm: fe YmX1 */

/* qhasm: fe A */

/* qhasm: fe B */

/* qhasm: fe C */

/* qhasm: fe CAT */

/* qhasm: YpX1 = Y1+X1 */
/* asm 1: fe_add(>YpX1=fe#1,<Y1=fe#12,<X1=fe#11); */
/* asm 2: fe_add(>YpX1=r->X,<Y1=p->Y,<X1=p->X); */
fe_add(r->X,p->Y,p->X);

/* qhasm: YmX1 = Y1-X1 */
/* asm 1: fe_sub(>YmX1=fe#2,<Y1=fe#12,<X1=fe#11); */
/* asm 2: fe_sub(>YmX1=r->Y,<Y1=p->Y,<X1=p->X); */
fe_sub(r->Y,p->Y,p->X);

/* qhasm: A = YpX1*ymx2 */
/* asm 1: fe_mul(>A=fe#3,<YpX1=fe#1,<ymx2=fe#16); */
/* asm 2: fe_mul(>A=r->Z,<YpX1=r->X,<ymx2=q->yminusx); */
fe_mul(r->Z,r->X,q->yminusx);

/* qhasm: B = YmX1*ypx2 */
/* asm 1: fe_mul(>B=fe#2,<YmX1=fe#2,<ypx2=fe#15); */
/* asm 2: fe_mul(>B=r->Y,<YmX1=r->Y,<ypx2=q->yplusx); */
fe_mul(r->Y,r->Y,q->yplusx);

/* qhasm: C = xy2d2*T1 */
/* asm 1: fe_mul(>C=fe#4,<xy2d2=fe#17,<T1=fe#14); */
/* asm 2: fe_mul(>C=r->T,<xy2d2=q->xy2d,<T1=p->T); */
fe_mul(r->T,q->xy2d,p->T);

/* qhasm: CAT = 2*Z1 */
/* asm 1: fe_add(>CAT=fe#5,<Z1=fe#13,<Z1=fe#13); */
/* asm 2: fe_add(>CAT=t0,<Z1=p->Z,<Z1=p->Z); */
fe_add(t0,p->Z,p->Z);

/* qhasm: X3 = A-B */
/* asm 1: fe_sub(>X3=fe#1,<A=fe#3,<B=fe#2); */
/* asm 2: fe_sub(>X3=r->X,<A=r->Z,<B=r->Y); */
fe_sub(r->X,r->Z,r->Y);

/* qhasm: Y3 = A+B */
/* asm 1: fe_add(>Y3=fe#2,<A=fe#3,<B=fe#2); */
/* asm 2: fe_add(>Y3=r->Y,<A=r->Z,<B=r->Y); */
fe_add(r->Y,r->Z,r->Y);

/* qhasm: Z3 = CAT-C */
/* asm 1: fe_sub(>Z3=fe#3,<CAT=fe#5,<C=fe#4); */
/* asm 2: fe_sub(>Z3=r->Z,<CAT=t0,<C=r->T); */
fe_sub(r->Z,t0,r->T);

/* qhasm: T3 = CAT+C */
/* asm 1: fe_add(>T3=fe#4,<CAT=fe#5,<C=fe#4); */
/* asm 2: fe_add(>T3=r->T,<CAT=t0,<C=r->T); */
fe_add(r->T,t0,r->T);

/* qhasm: return */
