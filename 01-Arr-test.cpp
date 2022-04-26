#include "01-Arr.cpp"
int main()
{
    struct Arr arr;
    // 初始化长度为6的数组
    init_arr(&arr, 6);

    // 追加元素
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);

    traverse_arr(&arr); // 输出结果为 1 2 3 4

    // 在索引为0的位置插入6
    insert_arr(&arr, 0, 5);
    traverse_arr(&arr); // 输出结果为 5 1 2 3 4

    // 在索引为0的位置删除元素
    int delval; // 用于接收删除的元素
    delete_arr(&arr, 0, &delval);
    traverse_arr(&arr); // 输出结果为 1 2 3 4

    // 数组倒置
    inverse_arr(&arr);
    traverse_arr(&arr); // 输出结果为 4 3 2 1

    // 数组排序
    sort_arr(&arr);
    traverse_arr(&arr); // 输出结果为 1 2 3 4

    return 0;
}
