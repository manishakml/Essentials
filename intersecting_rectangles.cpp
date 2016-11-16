//EPI 5.12
typedef struct rectangle{
  int x;
  int y;
  int w;
  int h;
}Rectangle;

bool intersecting(const Rectangle &R, const Rectangle &S) {
  return R.x+R.w >= S.x &&  R.x <= S.x+S.w && R.y <= S.y+S.h && R.y+R.h >= S.y;
}
Rectangle intersecting_rectangle(Rectangle R, Rectangle S) {
  if(intersecting(R,S)) {
    return {max(R.x, S.x), max(R.y,S.y), min(R.x+R.w,S.x+S.w)-max(R.x,S.x), min(R.y+R.h, S.y+S.h)-max(R.y,S.y)};
  } else {
    return {0,0,-1,-1};
}
