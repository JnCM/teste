#include <stdio.h>
#include <stdlib.h>

int rng(int seed){
	int num, outbitLFSR;
	int LFSR_reg, CASR_reg;
	CASR_reg = seed;
	LFSR_reg = seed;
	CASR_reg = CASR_reg ^ (CASR_reg-1);
	//printf("CASR_outCASR: %d\n", CASR_reg);
	outbitLFSR = 1;
	LFSR_reg = LFSR_reg ^ outbitLFSR;
	//printf("LFSR_varLFSR: %d\n", LFSR_reg);
	num = LFSR_reg ^ CASR_reg;
	/*if(num < 0){
		num *= -1;
	}*/
	return num;
}

int main(){
  int n_node, n_edge, n, size_offset, WALK;
  n_node = 47;
  n_edge = 60;
  n = 7;
  size_offset = 62;
  WALK = 4;
  int state, i, j, k, a, b;
  int pos_a_X, pos_a_Y, pos_b_X, pos_b_Y, xi, xj;
  int sum_mesh=0, sum_1hop=0, diff_pos_x, diff_pos_y;
  int e_a[n_edge], e_b[n_edge];
  int pos_X[n_node], pos_Y[n_node];
  int grid[n][n];
  int seed = 212681713;
  int opcX0[62] = {0, 0, 1, 0,-1,-1, 1, 1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};
  int opcX1[62] = {0,-1, 0, 1, 0,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};
  int opcX2[62] = {0, 0, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};
  int opcX3[62] = {0,-1, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};

  int opcY0[62] = {0, 1, 0,-1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
   2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};
  int opcY1[62] = {0, 0, 1, 0,-1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
  2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};
  int opcY2[62] = {0,-1, 0, 1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
  2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};
  int opcY3[62] = {0, 0, 0,-1, 1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
  2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};

  state = 0;
  while(state != 5){
    switch(state){
      case 0:
    	  e_a[0] = 45; e_b[0] = 43;
    	  e_a[1] = 43; e_b[1] = 46;
    	  e_a[2] = 43; e_b[2] = 40;
    	  e_a[3] = 40; e_b[3] = 37;
    	  e_a[4] = 40; e_b[4] = 36;
    	  e_a[5] = 37; e_b[5] = 42;
    	  e_a[6] = 37; e_b[6] = 33;
    	  e_a[7] = 42; e_b[7] = 39;
    	  e_a[8] = 39; e_b[8] = 35;
    	  e_a[9] = 35; e_b[9] = 31;
    	  e_a[10] = 35; e_b[10] = 28;
    	  e_a[11] = 28; e_b[11] = 19;
    	  e_a[12] = 19; e_b[12] = 8;
    	  e_a[13] = 19; e_b[13] = 13;
    	  e_a[14] = 8; e_b[14] = 2;
    	  e_a[15] = 13; e_b[15] = 2;
    	  e_a[16] = 31; e_b[16] = 23;
    	  e_a[17] = 23; e_b[17] = 13;
    	  e_a[18] = 33; e_b[18] = 26;
    	  e_a[19] = 33; e_b[19] = 25;
    	  e_a[20] = 26; e_b[20] = 15;
    	  e_a[21] = 15; e_b[21] = 4;
    	  e_a[22] = 15; e_b[22] = 29;
    	  e_a[23] = 4; e_b[23] = 21;
    	  e_a[24] = 4; e_b[24] = 0;
    	  e_a[25] = 21; e_b[25] = 10;
    	  e_a[26] = 10; e_b[26] = 2;
    	  e_a[27] = 29; e_b[27] = 23;
    	  e_a[28] = 29; e_b[28] = 20;
    	  e_a[29] = 20; e_b[29] = 9;
    	  e_a[30] = 9; e_b[30] = 2;
    	  e_a[31] = 25; e_b[31] = 14;
    	  e_a[32] = 14; e_b[32] = 3;
    	  e_a[33] = 3; e_b[33] = 0;
    	  e_a[34] = 36; e_b[34] = 32;
    	  e_a[35] = 32; e_b[35] = 25;
    	  e_a[36] = 32; e_b[36] = 24;
    	  e_a[37] = 24; e_b[37] = 16;
    	  e_a[38] = 24; e_b[38] = 14;
    	  e_a[39] = 24; e_b[39] = 34;
    	  e_a[40] = 16; e_b[40] = 30;
    	  e_a[41] = 16; e_b[41] = 5;
    	  e_a[42] = 5; e_b[42] = 0;
    	  e_a[43] = 5; e_b[43] = 17;
    	  e_a[44] = 17; e_b[44] = 6;
    	  e_a[45] = 17; e_b[45] = 12;
    	  e_a[46] = 6; e_b[46] = 1;
    	  e_a[47] = 12; e_b[47] = 2;
    	  e_a[48] = 30; e_b[48] = 22;
    	  e_a[49] = 22; e_b[49] = 13;
    	  e_a[50] = 22; e_b[50] = 11;
    	  e_a[51] = 11; e_b[51] = 2;
    	  e_a[52] = 34; e_b[52] = 27;
    	  e_a[53] = 27; e_b[53] = 18;
    	  e_a[54] = 18; e_b[54] = 7;
    	  e_a[55] = 7; e_b[55] = 1;
    	  e_a[56] = 46; e_b[56] = 44;
    	  e_a[57] = 44; e_b[57] = 41;
    	  e_a[58] = 41; e_b[58] = 38;
    	  e_a[59] = 38; e_b[59] = 34;

        for(i=0; i<n; i++){
          for(j=0; j<n; j++){
            grid[i][j] = -1;
          }
        }
        for(i=0; i<n_node; i++){
          pos_X[i] = -1;
          pos_Y[i] = -1;
        }
        a = e_a[0];
		pos_X[a] = rng(seed) % n;
		seed = seed + 1;
        pos_Y[a] = rng(seed) % n;
        seed = seed + 1;
        grid[pos_X[a]][pos_Y[a]] = a;
        i=0;
        j=0;
        state = 1;
        break;
      case 1:
        if(i == n_edge){
          state = 4;
          i=0;
          break;
        }
        a = e_a[i];
        b = e_b[i];
        pos_a_X = pos_X[a];
        pos_a_Y = pos_Y[a];
        pos_b_X = pos_X[b];
        pos_b_Y = pos_Y[b];
        if(i==0){
          state = 3;
        }
        else{
          state = 2;
        }
        break;
      case 2://Posição X de a
        if(pos_a_X != -1){
          state = 3;
          j=0;
          break;
        }
        k = rng(seed) % WALK;
        seed = seed + 1;
        if (pos_b_X == -1) {
          if(k == 0){
            xi = (rng(seed) % n) + opcX0[j];
            seed = seed + 1;
            xj = (rng(seed) % n) + opcY0[j];
            seed = seed + 1;
          }
          else if(k == 1){
            xi = (rng(seed) % n) + opcX1[j];
            seed = seed + 1;
            xj = (rng(seed) % n) + opcY1[j];
            seed = seed + 1;
          }
          else if(k == 2){
            xi = (rng(seed) % n) + opcX2[j];
            seed = seed + 1;
            xj = (rng(seed) % n) + opcY2[j];
            seed = seed + 1;
          }
          else{
            xi = (rng(seed) % n) + opcX3[j];
            seed = seed + 1;
            xj = (rng(seed) % n) + opcY3[j];
            seed = seed + 1;
          }
        }
        else {
          if(k == 0){
            xi = pos_b_X + opcX0[j];
            xj = pos_b_Y + opcY0[j];
          }
          else if(k == 1){
            xi = pos_b_X + opcX1[j];
            xj = pos_b_Y + opcY1[j];
          }
          else if(k == 2){
            xi = pos_b_X + opcX2[j];
            xj = pos_b_Y + opcY2[j];
          }
          else{
            xi = pos_b_X + opcX3[j];
            xj = pos_b_Y + opcY3[j];
          }
        }
        j++;
        if(grid[xi][xj] == -1 && xi < n && xi >= 0 && xj < n && xj >= 0){
          grid[xi][xj] = a;
          pos_X[a] = xi;
          pos_Y[a] = xj;
          pos_a_X = xi;
          pos_a_Y = xj;
        }
        else if(j >= size_offset){
          printf("No solution\n");
          return 0;
        }
        if(pos_a_X == -1){
          state = 2;
        }
        else{
          state = 3;
          j=0;
        }
        break;
      case 3://Posição X de b
        if(pos_b_X != -1){
          state = 1;
          j=0;
          i++;
          break;
        }
        k = rng(seed) % WALK;
        seed = seed + 1;
        if(k == 0){
          xi = pos_a_X + opcX0[j];
          xj = pos_a_Y + opcY0[j];
        }
        else if(k == 1){
          xi = pos_a_X + opcX1[j];
          xj = pos_a_Y + opcY1[j];
        }
        else if(k == 2){
          xi = pos_a_X + opcX2[j];
          xj = pos_a_Y + opcY2[j];
        }
        else{
          xi = pos_a_X + opcX3[j];
          xj = pos_a_Y + opcY3[j];
        }
        j++;
        if(grid[xi][xj] == -1 && xi < n && xi >= 0 && xj < n && xj >= 0){
          grid[xi][xj] = b;
          pos_b_X = xi;
          pos_b_Y = xj;
          pos_X[b] = xi;
          pos_Y[b] = xj;
          state = 1;
          j=0;
          i++;
          break;
        }
        else if(j >= size_offset){
          printf("No solution\n");
          return 0;
        }
        if(pos_b_X == -1){
          state = 3;
        }
        else{
          state = 1;
          j=0;
          i++;
        }
        break;
      case 4://Evaluation
        if(i == n_edge){
          state = 5;
          break;
        }
        a = e_a[i];
        b = e_b[i];
        diff_pos_x = pos_X[a]-pos_X[b];
        if(diff_pos_x < 0){
          diff_pos_x *= -1;
        }
        diff_pos_y = pos_Y[a]-pos_Y[b];
        if(diff_pos_y < 0){
          diff_pos_y *= -1;
        }
        sum_mesh += diff_pos_x + diff_pos_y - 1;
        sum_1hop += (diff_pos_x/2 + diff_pos_x%2) + (diff_pos_y/2 + diff_pos_y%2) - 1;
        i++;
        break;
    }
  }
  //Exibindo o grid:
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      printf("%3d ", grid[i][j]);
    }
    printf("\n");
  }
  printf("\nEvaluation = %d\nEvaluation 1-hop = %d\n", sum_mesh, sum_1hop);
  return 1;
}