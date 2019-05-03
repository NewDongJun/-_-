# 1.소프트웨어 19학번 신동준 
기컴프_개인과제
## 1.1 프로그램 설명
좌표가 입력되는 공간의 사이즈 마다 출력 되는 건물이 다르고 특정 건물이 출력 되는 구간 내에서는 공간의 사이즈에 따라 건물의 사이즈도 변하는 함수를 만든다.
그 함수를 메인 함수에 돌린다.

# 2.함수 구성 
## 2.1 매크로 함수
 	#define SWAP(s,e)			{int t=s; s=e; e=t;}

데이터를 크기에 따라 바꿔주는 함수

## 2.2 main 함수


	int main()
	{
	
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
	}
	
main 함수에서는 매크로 함수를 사용해서 크기에 따라서 좌표를 재정의 하고 build 함수만을 사용해서 건물을 지음 


	
## 2.3 build 함수
	//건물을 생성하는 함수     //하얗게 불태웠다.
	void build(int sx, int sy, int sz, int ex, int ey, int ez)
	{
		BlockID air = createBlock(BLOCK_AIR);
		WoolID wool = createWool(COLOR_BROWN);
		BlockID glowstone = createBlock(BLOCK_GLOWSTONE);
		BlockID gold = createBlock(BLOCK_GOLD);
		BlockID iron = createBlock(BLOCK_IRON);
		BlockID glass = createBlock(BLOCK_GLASS);
		BlockID diamond = createBlock(BLOCK_DIAMOND);

		DoorID door = createDoor(DOOR_OAK);

		//축별 좌표의 차 
		int xlen = ex - sx;
		int ylen = ey - sy;
		int zlen = ez - sz;

		//x,y,z좌표의 평균 좌표 
		int mx = (ex + sx) / 2;
		int my = (ey + sy) / 2;
		int mz = (ez + sz) / 2;

		//x,y,z중 좌표가 겹칠경우 예외처리하고 건물 생성 하지 않는다.
		if (xlen == 0 || ylen == 0 || zlen == 0) {
			printf("x,y,z중 하나 이상의 좌표가 겹치므로 건물을 생성하지 않는다.");
		}

		//x의 좌표의 차의 길이에 따라서 각가 다른 모양의 건물을 생성
		else {

			//가로등 생성
			if (xlen < 5)
			{
				//가로등 생성 코드 
			}


			//just 피라미드  //이게 젤 어렵네 //ㅇ아아아아아아아앙
			else if (xlen < 16)
			{
				//피라미드형 건물 생성 코드 
			}


			//창문 있는 건물을 만들어보자 가능하면 문도
			else if (xlen < 31)
			{
				//직육면체 건물 생성 코드 
			}


			//대형 구조물  아아앙아 math.h 좀 써서 좀 근사한거좀 만들어 볼려 했는데 수학을 못하네 ㅠㅠ 라이브러리를 쓸줄 몰라 ㅠㅠ
			else
			{
				//대형 구조물 생성 코드 
			}
		}
	}

	
	




