# 1.소프트웨어 19학번 신동준 
기컴프_개인과제

# 2.함수 구성 
## 2.1 매크로 함수
'''c

#define SWAP(s,e)			{int t=s; s=e; e=t;}
'''
데이터를 크기에 따라 바꿔주는 함수

## 2.2 main 함수
'''c


	int sx, sy, sz, ex, ey, ez;
	printf("두개의 좌표를 입럭하시오. 예시: x1 y1 z1 x2 y2 z2 \n");
	scanf("%d %d %d %d %d %d", &sx, &sy, &sz, &ex, &ey, &ez);

	//좌표를 축의 크기별로 재정의
	if (sx > ex) SWAP(sx, ex);
	if (sy > ey) SWAP(sy, ey);
	if (sz > ez) SWAP(sz, ez);

	//printf("%d %d %d %d %d %d", sx, sy, sz, ex, ey, ez);

	build(sx, sy, sz, ex, ey, ez);

	return 0;

'''


