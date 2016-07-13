#include <bits/stdc++.h>

using namespace std;

int kspecial(int x);

const int M = 1e7 + 0;

int main()
{
	int A[][10] = {1,0,0,0,0,0,0,0,0,0,10000001,8585584,4668170,1839676,537163,97127,9731,105,0,0,20000001,18585584,11099242,4669498,1528913,330136,43330,1374,0,0,30000001,27509737,16523850,7108937,2380185,526134,70312,2237,0,0,40000001,36223280,21690988,9448103,3233916,750128,103012,3841,0,0,50000001,44864377,26637559,11672814,4004411,938968,130607,4966,0,0,60000001,53490808,31459523,13693370,4650994,1076976,145666,5357,0,0,70000001,62089471,36237791,15785267,5409887,1267284,172922,6213,0,0,80000001,70749551,41169330,17825721,6045072,1403267,189643,7085,0,0,90000001,79346206,45932111,19864708,6731161,1563800,212578,8097,0,0,100000001,87944418,50717867,21896051,7399553,1722932,237620,9215,0,0,110000001,97944418,57148944,24725787,8391470,1955805,271289,10464,0,0,120000001,107944418,63580010,27554579,9384630,2189478,303604,11979,0,0,130000001,117944418,70770342,31077125,10831526,2596498,377608,17377,89,0,140000001,127944418,77613582,34418551,12228373,3035584,464618,24460,242,0,150000001,137944418,84177470,37673350,13536259,3414151,536933,30293,357,0,160000001,147944418,90715044,40694179,14674334,3716788,586216,33713,501,0,170000001,157944418,97186189,43724735,15934062,4104492,660757,39050,599,0,180000001,167944418,103840179,46804913,17056388,4399479,708781,43202,744,0,190000001,177944418,110299187,49810346,18248831,4726166,771893,48386,840,0,200000001,187944418,116787798,52831298,19393799,5052620,837183,53968,945,0,210000001,196868589,122212330,55270849,20245042,5248600,864141,54849,945,0,220000001,206868589,129402650,58793423,21691972,5655560,938144,60253,1040,0,230000001,215792698,134827466,61232098,22543579,5852604,964190,61272,1040,0,240000001,224831783,140681523,64118559,23758071,6236617,1038114,66792,1127,0,250000001,233755911,146302775,66982050,24890243,6558340,1097380,70883,1203,0,260000001,242680104,151819305,69633583,25885384,6822858,1137849,73164,1294,0,270000001,251604442,157294877,72292663,27005453,7156216,1194063,76412,1318,0,280000001,260582214,162950555,74943078,27974565,7406033,1234445,79741,1413,0,290000001,269506555,168424414,77574893,29005991,7685011,1285131,83334,1472,0,300000001,278441909,173951490,80180197,29992505,7966009,1340357,87545,1545,0,310000001,287155480,179118554,82519438,30846270,8189907,1373083,89156,1545,0,320000001,297155480,185961797,85860821,32243185,8628934,1460120,96270,1670,0,330000001,306194583,191815780,88747362,33457647,9012961,1534046,101777,1759,0,340000001,314908115,196982978,91086323,34311408,9237724,1565667,103817,1759,0,350000001,323676050,202412850,93765213,35394163,9595174,1637365,109854,1879,0,360000001,332428565,207723992,96265616,36359302,9877807,1685428,113141,2014,0,370000001,341142084,212931648,98803996,37482544,10256299,1758882,118766,2109,0,380000001,349925551,218340353,101335470,38446701,10532010,1806274,122877,2250,0,390000001,358650020,223599011,103853220,39435449,10838255,1868239,128256,2351,0,400000001,367363514,228823836,106383408,40442122,11156463,1931926,134398,2451,0,410000001,376004540,233770643,108607846,41212660,11345391,1959507,135515,2451,0,420000001,386004540,240334538,111862584,42520564,11724061,2031742,141349,2577,0,430000001,394928675,245955773,114726089,43652777,12045715,2091022,145459,2644,0,440000001,403696613,251385631,117405089,44735452,12403065,2162851,151436,2774,0,450000001,412338087,256331620,119628655,45507758,12592487,2189126,152838,2774,0,460000001,421010868,261399768,122028950,46409953,12838234,2228954,155592,2902,0,470000001,429664128,266444589,124475415,47401120,13148113,2288063,159835,2980,0,480000001,438377176,271636424,126893849,48282164,13383984,2327879,163375,3107,0,490000001,447018666,276626841,129295314,49244584,13660021,2382787,168392,3228,0,500000001,455672212,281688682,131699619,50136094,13922196,2436464,173123,3319,0,510000001,464298635,286510691,133719961,50782974,14060114,2451468,173540,3319,0,520000001,474298635,293048262,136740845,51921035,14362665,2500811,176962,3450,0,530000001,483222820,298564801,139392366,52916138,14627282,2541238,179225,3551,0,540000001,491975334,303875953,141892747,53881246,14909935,2589336,182503,3683,0,550000001,500648142,308943951,144293199,54783452,15155672,2629111,185281,3805,0,560000001,509274687,313765291,146314568,55429542,15293684,2644598,185431,3805,0,570000001,517912276,318685944,148566754,56304077,15543652,2684709,187874,3901,0,580000001,526611553,323761587,150787350,57052994,15724451,2709455,190034,4039,0,590000001,535246869,328665680,152996612,57857683,15935431,2743082,192395,4144,0,600000001,543885810,333603454,155202383,58631539,16142551,2777421,194926,4245,0,610000001,552484454,338381755,157294248,59390498,16332790,2804718,195762,4245,0,620000001,562484454,344852868,160324910,60650085,16720570,2879232,201121,4339,0,630000001,571408810,350328429,162983930,61770272,17053826,2935489,204367,4360,0,640000001,580122350,355536066,165522296,62893581,17432241,3008925,210042,4447,0,650000001,588775616,360580939,167968665,63884817,17742061,3068075,214272,4525,0,660000001,597413180,365501593,170220890,64759265,17992153,3108101,216750,4618,0,670000001,606012047,370279452,172313356,65516724,18184828,3133470,218195,4618,0,680000001,614684313,375317172,174592099,66375619,18423828,3172965,221403,4714,0,690000001,623294066,380188002,176867707,67274070,18691941,3224030,225094,4783,0,700000001,631903940,385068729,179125571,68167734,18968097,3278797,229559,4848,0,710000001,640564020,390000268,181166025,68802919,19104080,3295518,230431,4848,0,720000001,650564020,396654274,184246141,69925325,19399019,3343572,234577,4982,0,730000001,659541784,402310045,186896345,70894661,19648702,3384005,237893,5074,0,740000001,668325228,407718785,189427816,71858740,19924493,3431415,241976,5213,0,750000001,677038274,412910695,191846123,72739964,20160100,3471380,245518,5327,0,760000001,685737579,417986227,194066841,73488873,20340832,3496157,247695,5451,0,770000001,694409850,423023894,196345572,74347921,20579713,3535679,250895,5553,0,780000001,703070507,427953823,198386742,74983771,20715878,3551926,251710,5553,0,790000001,711741535,432972215,200621440,75771585,20918409,3586470,254872,5658,0,800000001,720414247,438015879,202846626,76541144,21120974,3621777,258057,5756,0,810000001,729010879,442778696,204885641,77227178,21281511,3644707,259085,5756,0,820000001,739010879,449237705,207891074,78419621,21608198,3707819,264269,5852,0,830000001,747935221,454711537,210522993,79450910,21887258,3758454,267900,5900,0,840000001,756659699,459970196,213040762,80439568,22193575,3820425,273254,6010,0,850000001,765301183,464960678,215442118,81402071,22469565,3875350,278278,6123,0,860000001,773936505,469864729,217651596,82206485,22680608,3909016,280630,6230,0,870000001,782546231,474735596,219927231,83104855,22948761,3960080,284327,6298,0,880000001,791217253,479753990,222161951,83892727,23151132,3994708,287490,6403,0,890000001,799814055,484515479,224204187,84575266,23313461,4017169,288627,6403,0,900000001,808423334,489395600,226430508,85384414,23539630,4062213,292908,6473,0,910000001,817021520,494181454,228461643,86052942,23698799,4087228,294016,6473,0,920000001,827021520,500670003,231482764,87197682,24025435,4152472,299581,6581,0,930000001,835956874,506197079,234088068,88184196,24306433,4207698,303792,6654,0,940000001,844670445,511421716,236618436,89190774,24624771,4271197,310018,6754,0,950000001,853323990,516483504,239022866,90082160,24887022,4324840,314758,6846,0,960000001,861962906,521421343,241228657,90855933,25094165,4359149,317323,6943,0,970000001,870572797,526302068,243486461,91749630,25370314,4413979,321741,7010,0,980000001,879245489,531345753,245711597,92519221,25572951,4449212,324936,7116,0,990000001,887854795,536225808,247938047,93328324,25799003,4494355,329178,7199,0,1000000001,896452993,541011657,249969182,93996859,25958128,4519404,330282,7199,0};

	int q;
	cin>>q;

	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;

		if(l/M != r/M)
		{
			int x = l/M;
			int y = r/M;

			int c = A[y][k] - A[x][k];

			x *= M;
			for(int i=x+1;i<l;i++)
				if(kspecial(i) >= k)	
					c--;

			y *= M;
			for(int i=y;i<r;i++)
				if(kspecial(i+1) >= k)
					c++;

			printf("%d\n",c);
		}
		else
		{
			int c = 0;

			for(int i=l;i<=r;i++)
				if(kspecial(i) >= k)
					c++;

			printf("%d\n",c);
		}
	}
}

int kspecial(int n)
{
	int A[10];
	memset(A,0,sizeof(A));

	int x = n;
	while(x)
	{
		A[x%10] = 1;
		x /= 10;
	}

	int k = 0;
	for(int i=1;i<10;i++)
		if(A[i] && n%i==0)
			k++;

	return k;
}
