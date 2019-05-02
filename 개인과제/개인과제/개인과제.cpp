#define _CRT_SECURE_NO_WARNINGS //scanf의 보안오류를 무시하기 위한 선언 

#include <iostream>
#include <math.h>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")


//건물을 생성하는 함수     //하얗게 불태웠다.
void build(int sx, int sy, int sz, int ex, int ey, int ez);


#define SWAP(s,e)			{int t=s; s=e; e=t;} //매크로함수 
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
	int mz = (ez + ey) / 2;


	//x,y,z중 좌표가 겹칠경우 예외처리하고 건물 생성 하지 않는다.
	if (xlen == 0 || ylen == 0 || zlen == 0) {
		printf("x,y,z중 하나 이상의 좌표가 겹치므로 건물을 생성하지 않는다.");
	}

	//x의 좌표의 차의 길이에 따라서 각가 다른 모양의 건물을 생성
	else {

		//가로등 생성
		if (xlen < 5)
		{
			for (int i = sy; i < ey; i++) {
				locateBlock(wool, mx, i, mz);
			}
			locateBlock(glowstone, mx, ey, mz);
		}



		//just 피라미드  //이게 젤 어렵네 //ㅇ아아아아아아아앙
		else if (xlen < 16)
		{
			int z;  //블록이 공간을 넘어가지 않기위해 만든 변수 k가    z는 짧은 거의 차 나누기 2
			int len;
			if (xlen < zlen) {
				z = xlen / 2;
				ez = sz + xlen;   //x와 z의 차이를 맞춰줌
				len = xlen / 2;

			}
			else {
				z = zlen / 2;
				ex = sx + zlen;   //x와 z의 차이를 맞춰줌
				len = zlen / 2;
			}

			//ex 또는 ez값이 바뀌면서 평균 좌표의 재정의  
			mx = (ex + sx) / 2;
			my = (ey + sy) / 2;
			mz = (ez + ey) / 2;


			//건물을 만듦
			int k = 0;
			for (int i = ey - 1; i >= sy; i--) {

				if (k > z) k--;  //블록이 좌표를 넘어가지 않도록 k값 증가를 막음

				for (int n = 0; n <= 2 * k; n++) {
					for (int j = 0; j <= 2 * k; j++) {

						if (i % 2 == 0)
							locateBlock(diamond, mx - k + n, i, mz - k + j);
						else
							locateBlock(glass, mx - k + n, i, mz - k + j);
					}
				}
				k++;
			}

			//건물 안쪽을 air을 채워서 비워줌 
			k = 0;
			for (int i = ey - 2; i >= sy; i--) {

				if (k > z - 1) k--;  //블록이 좌표를 넘어가지 않도록 k값 증가를 막음

				for (int n = 0; n <= 2 * k; n++) {
					for (int j = 0; j <= 2 * k; j++) {
						locateBlock(air, mx - k + n, i, mz - k + j);
					}
				}
				k++;
			}

			//건물가운데 발광석 기둥을 세워줌 
			for (int i = sy; i < ey; i++) {
				locateBlock(glowstone, mx, i, mz);
			}

			//공기를 채워서 입구 만들기 

			locateBlock(air, mx, sy, mz - len);
			locateBlock(air, mx, sy + 1, mz - len);
			locateBlock(air, mx, sy, mz - len + 1);
			locateBlock(air, mx, sy + 1, mz - len + 1);

			//installDoor(door, mx, sy, mx - len, FACING_NORTH);
		}



		//창문 있는 건물을 만들어보자 가능하면 문도
		else if (xlen < 31)
		{
			//건물을 세워줌 창문도 같이 만들어줌 
			for (int x = sx; x <= ex; x++) {
				for (int y = sy; y <= ey; y++) {
					for (int z = sz; z <= ez; z++) {

						if (y % 2 == 0) {
							locateBlock(iron, x, y, z);
						}
						else {
							locateBlock(glass, x, y, z);
						}
					}
				}
			}

			//건물안의 공간을 비워줌 
			for (int x = sx + 1; x <= ex - 1; x++) {
				for (int y = sy; y <= ey - 1; y++) {
					for (int z = sz + 1; z <= ez - 1; z++) {
						locateBlock(air, x, y, z);
					}
				}
			}

			//건물의 천장을 발광석으로 채워줌 
			for (int x = sx + 1; x <= ex - 1; x++) {
				for (int z = sz + 1; z <= ez - 1; z++) {
					locateBlock(glowstone, x, ey - 1, z);
				}
			}



			//건물의 문을 만들어줌 
			installDoor(door, mx, sy, sz, FACING_NORTH);
		}



		//대형 구조물  아아앙아 math.h 좀 써서 좀 근사한거좀 만들어 볼려 했는데 수학을 못하네 ㅠㅠ 라이브러리를 쓸줄 몰라 ㅠㅠ
		else
		{
			int min = xlen;
			if (min > ylen) min = ylen;
			if (min > zlen) min = zlen;

			int i = 1;
			while (i <= min) {

				for (int k = 0; k < i; k++) {
					locateBlock(diamond, sx, sy + k, sz);
				}
				sx++;
				sz++;
				i++;
			}
		}
	}
}