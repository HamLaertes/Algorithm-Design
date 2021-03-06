#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

struct point{
    double x;
    double y;
    point(double x, double y):x(x),y(y){}
    point(){return;}
};

class Solution
{
    public:
        bool cmp_x(const point &A, const point &B){
            return A.x < B.x;
        }
        bool cmp_y(const point &A, const point &B){
            return A.y < B.y;
        }

        double distance(const point &A, const point &B){
            return sqrt(pow(A.x-B.x, 2)+pow(A.y-B.y, 2));
        }
        double merge(vector<point> &points, double dis, int mid);
        double closest(vector<point> &points);
};

double Solution::merge(vector<point> & points, double dis, int mid)
{
	vector<point> left, right;
	for(int i=0;i<points.size();++i){
		if(points[i].x-points[mid].x<=0&&points[i].x-points[mid].x>-dis)
			left.push_back(points[i]);
		else if(points[i].x-points[mid].x>0&&points[i].x-points[mid].x<dis)
			right.push_back(points[i]);
	}
	sort(right.begin(), right.end(), cmp_y);//right 中的点按y坐标从小到大排列
	for(int i=0,index;i<left.size();++i){
		for(index=0;index<right.size()&&left[i].y<right[index].y;++index);
		for(int j=0;j<7&&index+j<right.size();++j){
			if(distance(left[i],right[j+index])<dis)
				dis=distance(left[i],right[j+index]);
		}
	}
	return dis;
}

double Solution::closest(vector<point> & points)
{
	if(points.size()==2) return distance(points[0], points[1]);
	if(points.size()==3) return min(distance(points[0], points[1]), min(distance(points[0], points[2]), 
		distance(points[1], points[2])));
	int mid=(points.size()>>1)-1;
	double d1, d2, d;
    vector<point> left(mid + 1), right(points.size() - mid - 1);
	copy(points.begin(), points.begin()+mid+1, left.begin());
	copy(points.begin()+mid+1, points.end(), right.begin());
	d1=closest(left);
	d2=closest(right);
	d=min(d1, d2);
	return merge(points, d, mid);
}

int main()
{
    Solution st;
	int count;
	printf("点个数：");
	scanf("%d", &count);
	vector<point> points;
	double x, y;
	for (int i = 0; i < count; ++i)
	{
		printf("第%d个点", i);
		scanf("%lf%lf", &x, &y);
		point p(x, y);
		points.push_back(p);
	}
	sort(points.begin(), points.end(), st.cmp_x);
	printf("最近点对值：%lf", st.closest(points));
	return 0;
}