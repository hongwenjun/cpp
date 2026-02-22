#include <stdio.h>

/**
 * @brief 定义一个星期中各天的枚举类型。
 *
 * 该枚举类型用于表示一周中的每一天，从星期一到星期日。
 * 枚举值依次为：MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY。
 */
typedef enum {
  MONDAY,      /**< 星期一 */
  TUESDAY,     /**< 星期二 */
  WEDNESDAY,   /**< 星期三 */
  THURSDAY,    /**< 星期四 */
  FRIDAY,      /**< 星期五 */
  SATURDAY,    /**< 星期六 */
  SUNDAY       /**< 星期日 */
} Day;
/**
 * 主函数，程序的入口点。
 *
 * 该函数定义了一个枚举变量 `today`，表示当前的星期几，
 * 并通过 `switch` 语句根据 `today` 的值输出对应的星期信息。
 *
 * 返回值：
 *   int - 程序执行状态，0 表示正常退出。
 */
int main() {
  // 定义一个枚举变量 `today`，并初始化为 `TUESDAY`
  Day today = TUESDAY;

  // 使用 switch 语句根据 `today` 的值输出对应的星期信息
  switch (today) {
  case MONDAY:
    printf("It's Monday.\n");
    break;
  case TUESDAY:
    printf("It's Tuesday.\n");
    break;
  case WEDNESDAY:
    printf("It's Wednesday.\n");
    break;
  case THURSDAY:
    printf("It's Thursday.\n");
    break;
  case FRIDAY:
    printf("It's Friday.\n");
    break;
  case SATURDAY:
    printf("It's Saturday.\n");
    break;
  case SUNDAY:
    printf("It's Sunday.\n");
    break;
  }

  // 返回 0，表示程序正常结束
  return 0;
}