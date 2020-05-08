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
  n_node = 101;
  n_edge = 125;
  n = 11;
  size_offset = 62;
  WALK = 4;
  int state, i, j, k, a, b;
  int pos_a_X, pos_a_Y, pos_b_X, pos_b_Y, xi, xj;
  int sum_mesh=0, sum_1hop=0, diff_pos_x, diff_pos_y;
  int e_a[n_edge], e_b[n_edge];
  int pos_X[n_node], pos_Y[n_node];
  int grid[n][n];
  int seed = 556864168;
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
    	  e_a[0] = 100; e_b[0] = 99;
    	  e_a[1] = 99; e_b[1] = 97;
    	  e_a[2] = 99; e_b[2] = 98;
    	  e_a[3] = 98; e_b[3] = 96;
    	  e_a[4] = 96; e_b[4] = 92;
    	  e_a[5] = 92; e_b[5] = 87;
    	  e_a[6] = 87; e_b[6] = 82;
    	  e_a[7] = 82; e_b[7] = 75;
    	  e_a[8] = 75; e_b[8] = 66;
    	  e_a[9] = 75; e_b[9] = 70;
    	  e_a[10] = 70; e_b[10] = 60;
    	  e_a[11] = 60; e_b[11] = 49;
    	  e_a[12] = 49; e_b[12] = 36;
    	  e_a[13] = 36; e_b[13] = 23;
    	  e_a[14] = 23; e_b[14] = 9;
    	  e_a[15] = 9; e_b[15] = 2;
    	  e_a[16] = 66; e_b[16] = 58;
    	  e_a[17] = 66; e_b[17] = 56;
    	  e_a[18] = 56; e_b[18] = 44;
    	  e_a[19] = 44; e_b[19] = 31;
    	  e_a[20] = 31; e_b[20] = 18;
    	  e_a[21] = 18; e_b[21] = 4;
    	  e_a[22] = 4; e_b[22] = 1;
    	  e_a[23] = 58; e_b[23] = 45;
    	  e_a[24] = 58; e_b[24] = 48;
    	  e_a[25] = 48; e_b[25] = 35;
    	  e_a[26] = 35; e_b[26] = 22;
    	  e_a[27] = 22; e_b[27] = 7;
    	  e_a[28] = 7; e_b[28] = 2;
    	  e_a[29] = 45; e_b[29] = 33;
    	  e_a[30] = 45; e_b[30] = 31;
    	  e_a[31] = 33; e_b[31] = 20;
    	  e_a[32] = 33; e_b[32] = 27;
    	  e_a[33] = 27; e_b[33] = 14;
    	  e_a[34] = 14; e_b[34] = 2;
    	  e_a[35] = 20; e_b[35] = 5;
    	  e_a[36] = 5; e_b[36] = 1;
    	  e_a[37] = 97; e_b[37] = 95;
    	  e_a[38] = 97; e_b[38] = 94;
    	  e_a[39] = 95; e_b[39] = 91;
    	  e_a[40] = 91; e_b[40] = 86;
    	  e_a[41] = 86; e_b[41] = 81;
    	  e_a[42] = 81; e_b[42] = 74;
    	  e_a[43] = 74; e_b[43] = 65;
    	  e_a[44] = 65; e_b[44] = 55;
    	  e_a[45] = 55; e_b[45] = 43;
    	  e_a[46] = 43; e_b[46] = 30;
    	  e_a[47] = 30; e_b[47] = 17;
    	  e_a[48] = 17; e_b[48] = 3;
    	  e_a[49] = 3; e_b[49] = 0;
    	  e_a[50] = 94; e_b[50] = 93;
    	  e_a[51] = 94; e_b[51] = 90;
    	  e_a[52] = 93; e_b[52] = 88;
    	  e_a[53] = 88; e_b[53] = 83;
    	  e_a[54] = 83; e_b[54] = 76;
    	  e_a[55] = 83; e_b[55] = 79;
    	  e_a[56] = 79; e_b[56] = 71;
    	  e_a[57] = 71; e_b[57] = 62;
    	  e_a[58] = 62; e_b[58] = 51;
    	  e_a[59] = 51; e_b[59] = 38;
    	  e_a[60] = 38; e_b[60] = 27;
    	  e_a[61] = 38; e_b[61] = 25;
    	  e_a[62] = 25; e_b[62] = 12;
    	  e_a[63] = 12; e_b[63] = 2;
    	  e_a[64] = 76; e_b[64] = 69;
    	  e_a[65] = 76; e_b[65] = 67;
    	  e_a[66] = 67; e_b[66] = 56;
    	  e_a[67] = 69; e_b[67] = 57;
    	  e_a[68] = 69; e_b[68] = 61;
    	  e_a[69] = 61; e_b[69] = 50;
    	  e_a[70] = 50; e_b[70] = 37;
    	  e_a[71] = 37; e_b[71] = 27;
    	  e_a[72] = 37; e_b[72] = 24;
    	  e_a[73] = 24; e_b[73] = 10;
    	  e_a[74] = 10; e_b[74] = 2;
    	  e_a[75] = 57; e_b[75] = 44;
    	  e_a[76] = 57; e_b[76] = 46;
    	  e_a[77] = 46; e_b[77] = 34;
    	  e_a[78] = 46; e_b[78] = 31;
    	  e_a[79] = 34; e_b[79] = 21;
    	  e_a[80] = 21; e_b[80] = 8;
    	  e_a[81] = 21; e_b[81] = 6;
    	  e_a[82] = 8; e_b[82] = 2;
    	  e_a[83] = 6; e_b[83] = 1;
    	  e_a[84] = 90; e_b[84] = 89;
    	  e_a[85] = 90; e_b[85] = 86;
    	  e_a[86] = 89; e_b[86] = 85;
    	  e_a[87] = 89; e_b[87] = 84;
    	  e_a[88] = 85; e_b[88] = 80;
    	  e_a[89] = 80; e_b[89] = 73;
    	  e_a[90] = 73; e_b[90] = 64;
    	  e_a[91] = 64; e_b[91] = 54;
    	  e_a[92] = 54; e_b[92] = 40;
    	  e_a[93] = 54; e_b[93] = 41;
    	  e_a[94] = 40; e_b[94] = 27;
    	  e_a[95] = 41; e_b[95] = 28;
    	  e_a[96] = 28; e_b[96] = 14;
    	  e_a[97] = 28; e_b[97] = 16;
    	  e_a[98] = 16; e_b[98] = 2;
    	  e_a[99] = 84; e_b[99] = 77;
    	  e_a[100] = 84; e_b[100] = 78;
    	  e_a[101] = 77; e_b[101] = 67;
    	  e_a[102] = 78; e_b[102] = 68;
    	  e_a[103] = 78; e_b[103] = 72;
    	  e_a[104] = 72; e_b[104] = 63;
    	  e_a[105] = 63; e_b[105] = 53;
    	  e_a[106] = 53; e_b[106] = 42;
    	  e_a[107] = 53; e_b[107] = 40;
    	  e_a[108] = 42; e_b[108] = 29;
    	  e_a[109] = 29; e_b[109] = 15;
    	  e_a[110] = 15; e_b[110] = 2;
    	  e_a[111] = 68; e_b[111] = 59;
    	  e_a[112] = 68; e_b[112] = 56;
    	  e_a[113] = 59; e_b[113] = 52;
    	  e_a[114] = 59; e_b[114] = 47;
    	  e_a[115] = 47; e_b[115] = 32;
    	  e_a[116] = 32; e_b[116] = 19;
    	  e_a[117] = 19; e_b[117] = 4;
    	  e_a[118] = 19; e_b[118] = 11;
    	  e_a[119] = 11; e_b[119] = 2;
    	  e_a[120] = 52; e_b[120] = 40;
    	  e_a[121] = 52; e_b[121] = 39;
    	  e_a[122] = 39; e_b[122] = 26;
    	  e_a[123] = 26; e_b[123] = 13;
    	  e_a[124] = 13; e_b[124] = 2;

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
