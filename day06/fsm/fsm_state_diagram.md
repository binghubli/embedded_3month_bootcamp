# Day6 设备有限状态机流转图
## 状态集合
INIT 上电初始化、IDLE空闲、WORKING工作、ERROR故障、RECOVERY故障恢复

## 流转关系
1. INIT
   - EV_POWER_ON → IDLE

2. IDLE
   - EV_START → WORKING
   - EV_ERR → ERROR

3. WORKING
   - EV_STOP → IDLE
   - EV_ERR → ERROR
   - EV_TIMEOUT → ERROR

4. ERROR
   - EV_RESET → RECOVERY

5. RECOVERY
   - EV_POWER_ON → IDLE（恢复成功）
   - EV_TIMEOUT → ERROR（恢复超时失败）

## 两种实现对比
1. Switch-Case状态机
   优点：逻辑直观、新手易写；
   缺点：状态/事件增多后代码臃肿，维护麻烦。

2. 表驱动状态机
   优点：流转关系统一表格管理，新增状态只需加表项，解耦；
   缺点：需要查表，少量性能损耗，适合大型嵌入式设备。

## 测试覆盖说明
1. 正常流：INIT→IDLE→WORKING→IDLE 启停完整链路
2. 异常流：工作中报错→故障状态→复位恢复→回到空闲
3. 超时流：工作超时进故障、恢复阶段超时恢复失败