#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x, y;
};

float distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float min(float a, float b) {
    return (a < b) ? a : b;
}

int comparePoints(const void* a, const void* b) {
    struct Point* p1 = (struct Point*)a;
    struct Point* p2 = (struct Point*)b;
    return (p1->x - p2->x);
}

float closestPairUtil(struct Point P[], int n) {
  
    if (n == 2)
        return distance(P[0], P[1]);


    if (n == 1)
        return INFINITY;

    qsort(P, n, sizeof(struct Point), comparePoints);


    int mid = n / 2;
    struct Point midPoint = P[mid];

    float dl = closestPairUtil(P, mid);
    float dr = closestPairUtil(P + mid, n - mid);

    float d = min(dl, dr);

    struct Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(P[i].x - midPoint.x) < d) {
            strip[j] = P[i];
            j++;
        }
    }

    for (int i = 0; i < j; i++) {
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < d; k++) {
            float dist = distance(strip[i], strip[k]);
            if (dist < d)
                d = dist;
        }
    }

    return d;
}

float closestPair(struct Point P[], int n) {
    qsort(P, n, sizeof(struct Point), comparePoints);
    return closestPairUtil(P, n);
}

int main() {
    struct Point points[] = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
    int n = sizeof(points) / sizeof(points[0]);

    float closestDistance = closestPair(points, n);
    printf("The closest pair of points has a distance of %.2f\n", closestDistance);

    return 0;
}
