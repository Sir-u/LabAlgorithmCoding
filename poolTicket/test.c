#include <stdio.h>
#include <stdlib.h>

// 아이템 구조체
typedef struct {
    int price;
    int days;
    float ratio;
} Item;

// 비교함수: 요일 대 요금 비율이 높은 아이템이 먼저 정렬되도록 함
int compare(const void *a, const void *b)
{
    Item *item_a = (Item*)a;
    Item *item_b = (Item*)b;

    if (item_a->ratio < item_b->ratio) {
        return -1;
    } else if (item_a->ratio > item_b->ratio) {
        return 1;
    } else {
        return 0;
    }
}

int pull_greedy()
{
    Item items[10] = {0};
    int days = 0;
    int max_price = 0;
    int cur_days = 0;
    int i;

    // 요일 대 요금 비율 계산
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &items[i].price);
        items[i].days = i + 1;
        items[i].ratio = (float) items[i].price / items[i].days;
    }

    scanf("%d", &days);

    qsort(items, 10, sizeof(Item), compare);

    i = 0;
    while(cur_days < days)
    {
        if(cur_days + items[i].days <= days)
        {
            cur_days += items[i].days;
            max_price += items[i].price;
        }
        else {
            i++;
            int remaining_days = days - cur_days;
            max_price += (int)(remaining_days * items[i].ratio);
            break;
        }
    }

    return max_price;
}


int main()
{
    int ans = 0;
    int count = 0;
    int i;

    freopen("input.txt", "r", stdin);
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        ans = pull_greedy();
        printf("%d번째 최소 비용 : %d\n", i+1, ans);
    }
}