# 3个月嵌入式软件工程师高强度转行计划

目标岗位：科大讯飞/合肥方向嵌入式软件工程师  
当前基础：C、Python、Linux、STM32、ESP32有基础但遗忘较多  
总目标：用12周恢复并拉高到“可投递、有作品、能面试、能承担中级任务”的水平  
重要判断：3个月很难真正变成高级工程师，但可以用中级能力模型倒推训练，重点做出可展示项目、调试能力、代码质量和面试表达。

## 岗位画像

根据近期嵌入式软件岗位关键词整理，科大讯飞及同类岗位常见要求集中在：

- C/C++基础扎实，熟悉指针、内存、结构体、位操作、编译链接、Make/CMake。
- 熟悉Linux开发环境，能使用Shell/Python、gcc/gdb、strace、tcpdump、top/htop等工具。
- 熟悉STM32/GD32/ESP32等MCU，能完成GPIO、UART、I2C、SPI、ADC、PWM、DMA、中断、定时器开发。
- 熟悉FreeRTOS/RT-Thread/uCOS等RTOS，理解任务、队列、信号量、互斥锁、定时器、优先级和死锁。
- 熟悉常见通信协议：UART、RS485、CAN、I2C、SPI、Modbus、MQTT、TCP/IP。
- 具备嵌入式Linux应用开发能力：进程、线程、socket、IPC、文件IO、日志、守护进程、交叉编译。
- 能看懂基本原理图，会用万用表、示波器、逻辑分析仪定位问题。
- 有完整项目经验：需求拆解、模块设计、接口文档、自测用例、稳定性优化、问题复盘。

参考岗位页面：

- [科大讯飞招聘：实习岗位列表含嵌入式开发工程师](https://iflytek.zhiye.com/intern/jobs?sessionid=)
- [应届生求职网：科大讯飞嵌入式开发工程师-软开方向](https://www.yingjiesheng.com/job-007-971-114.html)
- [暨南大学就业信息：科大讯飞2026届春季校园招聘含嵌入式开发工程师](https://scdc.jnu.edu.cn/campus/view/id/1034674)
- [BOSS直聘：科大讯飞嵌入式招聘信息聚合](https://www.zhipin.com/zhaopin/3184068bd128b2b41XZ629W-/)
- [上海人工智能实验室：嵌入式软件工程师高阶能力参考](https://www.shlab.org.cn/joinus/detail/7649604717500893481?mode=social)

## 最终作品集要求

12周结束时必须有4个可展示成果，全部放到GitHub/Gitee：

1. `embedded-c-toolkit`：纯C数据结构、环形缓冲区、状态机、协议解析器、单元测试。
2. `stm32-freertos-sensor-node`：STM32 + FreeRTOS + 传感器 + UART/RS485/Modbus + 日志。
3. `esp32-iot-gateway`：ESP32 WiFi/MQTT/HTTP配置页/OTA/本地缓存。
4. `linux-edge-service`：Linux C/C++服务程序，串口采集、MQTT上报、多线程、日志、systemd部署。

每个项目必须包含：

- `README.md`：功能、架构图、硬件连接、编译烧录、运行截图/日志、问题记录。
- `docs/design.md`：模块设计、接口、状态机、错误码。
- `tests/`：能在PC上跑的核心逻辑测试。
- `CHANGELOG.md`：每周迭代记录。
- 至少一段演示视频或动图，展示真实运行结果。

## 每日固定节奏

每天建议投入8到10小时，按下面节奏执行：

- 08:30-09:00：复盘昨日问题，写今日任务清单。
- 09:00-11:30：核心知识学习和手写代码。
- 13:30-16:30：项目开发，必须有可运行增量。
- 16:45-18:00：调试、测试、记录问题。
- 19:30-21:00：面试题、八股、源码阅读、技术博客。
- 21:00-21:30：提交Git，写日报。

每日硬性产出：

- 至少1次Git提交。
- 至少1个可运行demo、测试用例或调试记录。
- 至少300字技术笔记。
- 遇到bug必须写：现象、假设、实验、结论、修复。

## 设备和环境

建议硬件：

- STM32开发板：STM32F103C8T6或STM32F407。
- ESP32开发板：ESP32-WROOM或ESP32-S3。
- USB转TTL模块、RS485模块、CAN模块、OLED/I2C传感器、温湿度传感器、按键、LED。
- ST-Link、逻辑分析仪、万用表；有条件加示波器。

软件环境：

- Windows + WSL2 Ubuntu。
- VS Code、Git、CMake、Make、gcc、gdb、clang-format、cppcheck。
- STM32CubeMX、STM32CubeIDE或Keil、OpenOCD。
- ESP-IDF。
- Mosquitto、MQTTX、Wireshark、tcpdump。
- QEMU可选，用于Linux和驱动概念练习。

## 知识点总清单

### C语言和工程能力

- 指针、数组、函数指针、二级指针、结构体、联合体、位域。
- 内存布局：栈、堆、全局区、只读区、代码区。
- `const`、`static`、`volatile`、`extern`、`inline`。
- 宏、条件编译、头文件保护、模块化封装。
- 编译链接、静态库、动态库、Makefile、CMake。
- 常见缺陷：越界、野指针、内存泄漏、重复释放、未初始化、整数溢出。
- 数据结构：链表、队列、环形缓冲区、哈希表、状态机。
- 代码规范：错误码、日志、断言、单元测试、接口文档。

### MCU和裸机

- GPIO、EXTI、中断优先级、SysTick。
- UART、I2C、SPI、ADC、PWM、DMA、定时器。
- 启动文件、链接脚本、向量表、Bootloader基础。
- HAL、LL、寄存器开发思想。
- 低功耗、看门狗、Flash读写、参数保存。
- 原理图阅读、时钟树、上拉下拉、电平转换。

### RTOS

- 任务创建、任务栈、优先级、时间片。
- 队列、信号量、互斥锁、事件组、软件定时器。
- 临界区、中断与任务通信。
- 优先级反转、死锁、栈溢出、内存碎片。
- 生产者消费者、状态机任务、通信任务、日志任务设计。

### 通信协议

- UART帧格式、校验和、CRC、超时重传。
- RS485半双工方向控制。
- I2C/SPI时序与调试。
- CAN帧、ID、滤波、仲裁。
- Modbus RTU寄存器模型、CRC16。
- TCP/UDP socket、粘包拆包、心跳、重连。
- MQTT主题、QoS、遗嘱、重连、离线缓存。

### 嵌入式Linux

- 文件IO、目录、设备文件、权限。
- 进程、线程、互斥锁、条件变量。
- 管道、消息队列、共享内存、Unix domain socket。
- TCP/UDP socket、select/poll/epoll基础。
- 串口termios编程。
- systemd服务、日志轮转、配置文件。
- 交叉编译、rootfs、BusyBox、设备树和驱动基本概念。
- 调试工具：gdb、strace、ltrace、valgrind、perf、tcpdump、Wireshark。

### 面试重点

- C语言内存和指针。
- 中断、DMA、volatile、临界区。
- RTOS任务通信和调度。
- UART/I2C/SPI/CAN/Modbus/MQTT。
- Linux进程线程、socket、IPC。
- 项目架构、bug定位、性能优化。
- 原理图和常用仪器。

## 第1周：恢复C语言战斗力和Linux开发环境

目标：把C语言从“会一点”恢复到“能写可维护模块”，搭好全套开发环境。

### Day 1

- 安装WSL2 Ubuntu、VS Code、Git、gcc、gdb、make、cmake、clang-format、cppcheck。
- 创建GitHub/Gitee仓库：`embedded-3month-bootcamp`。
- 写C语言自测：指针、数组、字符串、结构体、函数指针各10题。
- 产出：环境截图、`day01_c_basics.c`、日报。

### Day 2

- 复习内存布局、指针运算、二级指针、`const/static/extern/volatile`。
- 手写`strlen/strcpy/strcmp/memcpy/memmove`，处理边界条件。
- 用gdb调试段错误、越界、空指针。
- 产出：`libc_mini/`和gdb调试笔记。

### Day 3

- 学习编译流程：预处理、编译、汇编、链接。
- 写Makefile，生成静态库和动态库。
- 学习头文件组织、模块接口、错误码。
- 产出：`c_build_demo/`。

### Day 4

- 手写单链表、双向链表、队列、栈。
- 每个结构写增删改查和测试。
- 用Valgrind或AddressSanitizer检查内存错误。
- 产出：`ds/list.c`、`ds/queue.c`、测试报告。

### Day 5

- 手写环形缓冲区，支持单字节、多字节、满/空判断。
- 写UART接收模拟器，将随机分片数据送入ring buffer。
- 写协议帧解析雏形：帧头、长度、payload、CRC占位。
- 产出：`ringbuffer/`。

### Day 6

- 学习状态机设计：表驱动状态机、switch状态机。
- 写一个设备状态机：INIT、IDLE、WORKING、ERROR、RECOVERY。
- 写单元测试覆盖正常流、异常流、超时流。
- 产出：`fsm/`和状态图。

### Day 7

- 周复盘和补漏。
- 整理第1周所有代码，统一clang-format。
- 写第1篇博客：《嵌入式C模块化、ring buffer和状态机》。
- 面试训练：C语言50题，必须手写答案。

## 第2周：C高级、调试、协议解析器

目标：写出一个面试可讲的纯C协议栈小项目。

### Day 8

- 学习宏、位操作、位域、大小端、内存对齐。
- 写寄存器位操作宏：SET_BIT、CLEAR_BIT、READ_BIT、WRITE_FIELD。
- 写大小端转换和单元测试。
- 产出：`bitops/`。

### Day 9

- 学习CRC8、CRC16、CRC32原理和查表法。
- 实现Modbus CRC16。
- 用公开测试向量验证。
- 产出：`crc/`。

### Day 10

- 设计二进制私有协议：帧头、版本、命令、长度、序号、payload、CRC。
- 实现编码器和解码器。
- 支持半包、粘包、错包恢复。
- 产出：`protocol/encoder.c`、`protocol/decoder.c`。

### Day 11

- 增加命令处理框架：ping、get_info、set_config、read_sensor。
- 使用函数指针表分发命令。
- 设计错误码和日志宏。
- 产出：`protocol/dispatcher.c`。

### Day 12

- 写协议fuzz测试：随机输入、随机切片、错误CRC、异常长度。
- 用Sanitizer跑测试。
- 修复所有崩溃和内存错误。
- 产出：测试报告。

### Day 13

- 学习CMake和CTest。
- 将第1到2周代码整理为`embedded-c-toolkit`。
- 编写README、API文档、架构图。
- 产出：作品集项目1初版。

### Day 14

- 模拟面试：C语言、协议解析、状态机、内存问题。
- 录制5分钟项目讲解视频。
- 总结第2周问题，列出第3周硬件准备清单。
- 产出：项目1可展示版本。

## 第3周：STM32裸机基础恢复

目标：重新熟悉STM32外设、CubeMX、烧录、调试和基础硬件。

### Day 15

- 安装STM32CubeIDE/CubeMX、ST-Link驱动。
- 新建STM32工程，点亮LED，按键控制LED。
- 理解启动流程、时钟树、main函数前发生了什么。
- 产出：`stm32_gpio_button/`。

### Day 16

- 学习GPIO输入输出、上拉下拉、推挽开漏、外部中断。
- 用按键触发EXTI中断，做消抖。
- 用逻辑分析仪或串口日志记录中断行为。
- 产出：EXTI笔记。

### Day 17

- 学习USART轮询、中断、DMA接收。
- 实现串口命令行：`help/status/reboot/led on/led off`。
- 移植第2周ring buffer和协议解析器。
- 产出：`stm32_uart_cli/`。

### Day 18

- 学习定时器、PWM、输入捕获。
- 用PWM控制LED亮度或蜂鸣器。
- 用定时器实现1ms系统tick和软件定时器。
- 产出：timer/PWM demo。

### Day 19

- 学习ADC采样、DMA搬运、均值滤波。
- 读取电位器或传感器数据。
- 写数据校准函数和异常检测。
- 产出：`stm32_adc_dma/`。

### Day 20

- 学习I2C/SPI。
- 驱动OLED或I2C温湿度传感器；没有传感器则用EEPROM/模拟设备替代。
- 记录I2C常见错误：NACK、地址错、上拉问题。
- 产出：I2C/SPI驱动笔记。

### Day 21

- 周复盘：整理外设demo为统一仓库。
- 写博客：《STM32外设调试路径：GPIO/UART/TIM/ADC/I2C》。
- 面试训练：中断、DMA、volatile、时钟树、上拉下拉。
- 产出：第3周硬件演示视频。

## 第4周：FreeRTOS和工程架构

目标：从裸机进入RTOS，设计多任务嵌入式应用。

### Day 22

- 移植或启用FreeRTOS。
- 创建LED任务、串口任务、传感器任务。
- 学习任务栈、优先级、延时、调度。
- 产出：`freertos_task_demo/`。

### Day 23

- 学习队列和生产者消费者模型。
- 传感器任务采样，队列发送给日志任务。
- 串口命令控制采样周期。
- 产出：队列demo。

### Day 24

- 学习信号量、互斥锁、事件组。
- 实现按键中断释放信号量，任务响应事件。
- 构造一次优先级反转案例并解释。
- 产出：RTOS同步笔记。

### Day 25

- 学习软件定时器、看门狗、任务健康监测。
- 实现看门狗喂狗任务和任务心跳表。
- 任务卡死时进入错误状态机。
- 产出：watchdog/health monitor。

### Day 26

- 设计`stm32-freertos-sensor-node`架构。
- 模块划分：bsp、drivers、services、protocol、app、docs。
- 写接口文档、错误码、日志格式。
- 产出：项目2设计文档。

### Day 27

- 实现项目2第一版：采集传感器、串口输出、命令配置。
- 增加参数保存到Flash或模拟Flash。
- 增加故障注入：传感器失败、通信失败、CRC错误。
- 产出：项目2 v0.1。

### Day 28

- 周复盘和项目整理。
- 写博客：《FreeRTOS任务划分和嵌入式状态机》。
- 面试训练：RTOS 50题。
- 产出：项目2演示视频。

## 第5周：工业通信协议和可靠性

目标：补齐岗位常见协议，做出更像真实产品的节点。

### Day 29

- 学习RS485硬件、半双工、方向控制、终端电阻。
- STM32串口接RS485模块，完成收发。
- 没有模块则先写PC模拟器。
- 产出：RS485 demo。

### Day 30

- 学习Modbus RTU协议。
- 实现03读保持寄存器、06写单寄存器、16写多寄存器。
- 将传感器数据映射为寄存器表。
- 产出：Modbus slave。

### Day 31

- 学习Modbus异常码、超时、CRC错误、广播地址。
- 写PC端Python Modbus测试脚本。
- 做1000次连续读写稳定性测试。
- 产出：测试日志。

### Day 32

- 学习CAN基础：标准帧、扩展帧、仲裁、滤波。
- 如果有CAN模块，实现CAN收发；没有则学习并写socketCAN模拟。
- 产出：CAN学习笔记和demo。

### Day 33

- 增加日志系统：等级、模块名、时间戳、限频。
- 增加故障码系统：通信故障、传感器故障、配置故障。
- 增加运行统计：重启次数、错误次数、最大栈占用。
- 产出：项目2 v0.2。

### Day 34

- 做稳定性测试：连续运行6小时。
- 记录内存、栈、水位、错误计数。
- 修复发现的问题。
- 产出：稳定性报告。

### Day 35

- 周复盘。
- 写博客：《Modbus RTU从协议到STM32实现》。
- 面试训练：UART/RS485/CAN/CRC/协议解析。
- 产出：项目2可投递版本。

## 第6周：ESP32和联网能力

目标：做一个能联网、能配置、能OTA的IoT网关。

### Day 36

- 安装ESP-IDF，跑通hello world、blink、串口日志。
- 学习ESP-IDF工程结构、menuconfig、component。
- 产出：`esp32_basic/`。

### Day 37

- 学习WiFi STA/AP模式。
- 实现STA连接路由器，失败自动重连。
- 增加连接状态机和日志。
- 产出：WiFi manager。

### Day 38

- 学习MQTT。
- ESP32连接本地Mosquitto，发布传感器数据，订阅控制命令。
- 设计topic：`device/{id}/telemetry`、`device/{id}/cmd`。
- 产出：MQTT demo。

### Day 39

- 学习NVS参数存储。
- 保存WiFi、MQTT服务器、设备ID、采样周期。
- 实现恢复默认配置命令。
- 产出：config service。

### Day 40

- 学习HTTP server。
- 实现简单配置页面或REST接口。
- 支持查看状态、修改配置、重启设备。
- 产出：web config。

### Day 41

- 学习OTA基础。
- 实现本地HTTP OTA升级流程。
- 写升级失败保护和版本号。
- 产出：OTA demo。

### Day 42

- 周复盘。
- 整合为`esp32-iot-gateway` v0.1。
- 写博客：《ESP32 WiFi/MQTT/配置/OTA工程化实践》。
- 面试训练：MQTT、HTTP、NVS、OTA、重连。

## 第7周：嵌入式Linux应用开发

目标：能写Linux边缘服务，补齐科大讯飞这类AI/设备侧岗位常见能力。

### Day 43

- 复习Linux目录、权限、文件IO。
- 用C实现配置文件读取、日志写入、文件轮转。
- 学习`open/read/write/ioctl`。
- 产出：linux file IO demo。

### Day 44

- 学习进程、fork、exec、wait、信号。
- 写一个守护进程demo。
- 支持SIGTERM优雅退出、SIGHUP重载配置。
- 产出：daemon demo。

### Day 45

- 学习pthread、互斥锁、条件变量。
- 写生产者消费者：串口线程采集，MQTT线程发送，日志线程落盘。
- 产出：thread queue demo。

### Day 46

- 学习IPC：pipe、FIFO、共享内存、Unix domain socket。
- 写一个本地控制CLI，通过Unix socket控制服务。
- 产出：ipc control demo。

### Day 47

- 学习TCP/UDP socket、select/poll。
- 写TCP echo server和client。
- 处理粘包拆包、超时、断线重连。
- 产出：socket demo。

### Day 48

- 学习串口termios编程。
- Linux读取USB转TTL串口数据，接入第2周协议解析器。
- 如果暂无硬件，用`socat`创建虚拟串口测试。
- 产出：serial parser。

### Day 49

- 周复盘。
- 创建`linux-edge-service`项目架构。
- 写博客：《Linux C服务程序：线程、串口、socket和守护进程》。
- 面试训练：进程线程、IPC、socket、select/poll。

## 第8周：Linux边缘服务项目

目标：完成一个可部署、可监控、能与MCU/ESP32联动的Linux服务。

### Day 50

- 设计`linux-edge-service`。
- 模块：config、logger、serial、protocol、mqtt、storage、supervisor。
- 写设计文档和接口。
- 产出：项目3设计。

### Day 51

- 实现配置系统：INI/JSON任选一种。
- 实现日志系统：等级、文件、控制台、轮转。
- 写单元测试。
- 产出：config/logger。

### Day 52

- 实现串口模块：打开、配置、读写、重连。
- 接入第2周协议解析器。
- 使用虚拟串口做自动化测试。
- 产出：serial module。

### Day 53

- 实现MQTT客户端。
- 采集数据上报，接收命令下发到串口。
- 支持断线重连和离线缓存。
- 产出：mqtt bridge。

### Day 54

- 实现状态监控：运行时间、消息数、错误数、队列长度。
- 实现本地CLI：status、reload、send、quit。
- 产出：control CLI。

### Day 55

- 写systemd service文件。
- 支持开机自启、崩溃重启、日志查看。
- 写部署文档。
- 产出：deployment。

### Day 56

- 周复盘。
- 联调：STM32/ESP32/虚拟串口 -> Linux服务 -> MQTT。
- 录制演示视频。
- 面试训练：项目架构讲解10分钟。

## 第9周：交叉编译、构建系统、嵌入式Linux底层概念

目标：理解从PC代码到目标板部署的工程链路。

### Day 57

- 学习交叉编译概念：host、target、toolchain、sysroot。
- 安装ARM交叉编译工具链。
- 交叉编译hello world和`linux-edge-service`。
- 产出：cross compile note。

### Day 58

- 学习CMake toolchain file。
- 给项目添加交叉编译配置。
- 输出不同平台构建产物。
- 产出：CMake交叉编译脚本。

### Day 59

- 学习BusyBox、rootfs、init流程。
- 用QEMU或资料理解嵌入式Linux启动链路：BootROM、Bootloader、Kernel、rootfs、init。
- 画启动流程图。
- 产出：boot flow doc。

### Day 60

- 学习设备树基础：节点、compatible、reg、interrupts。
- 阅读一个简单DTS片段。
- 写“应用层如何通过设备文件访问驱动”的说明。
- 产出：device tree note。

### Day 61

- 学习Linux驱动基本框架：字符设备、file_operations、ioctl。
- 不强求写复杂驱动，重点理解用户态和内核态边界。
- 可选：写最小字符设备模块。
- 产出：driver basic note。

### Day 62

- 学习调试和性能工具：strace、ltrace、gdb、valgrind、perf、tcpdump。
- 对`linux-edge-service`做一次系统调试演练。
- 写一份“线上问题定位流程”。
- 产出：debug playbook。

### Day 63

- 周复盘。
- 写博客：《嵌入式Linux从交叉编译到部署》。
- 面试训练：交叉编译、启动流程、设备树、驱动基础。

## 第10周：综合项目和工程质量

目标：把作品做得像真实团队项目，而不是实验代码。

### Day 64

- 选定最终综合项目名称：`edge-sensor-system`。
- 架构：STM32采集和Modbus，ESP32网关，Linux边缘服务，MQTT上报。
- 写总设计文档和系统架构图。
- 产出：final project design。

### Day 65

- 统一协议：设备ID、消息ID、错误码、时间戳、寄存器表。
- 统一日志格式。
- 统一配置项。
- 产出：interface spec。

### Day 66

- 联调STM32和Linux服务。
- Linux服务读取STM32数据并上报MQTT。
- 写联调问题记录。
- 产出：STM32-Linux path。

### Day 67

- 联调ESP32和MQTT。
- ESP32接收云端命令并转发或模拟转发。
- 支持掉线重连。
- 产出：ESP32-MQTT path。

### Day 68

- 增加异常处理：串口断开、CRC错误、MQTT断开、配置损坏。
- 增加自动恢复策略。
- 产出：fault recovery。

### Day 69

- 写自动化测试脚本：虚拟串口、MQTT消息、压力测试。
- 跑1万条消息测试。
- 修复崩溃、泄漏、死锁。
- 产出：test report。

### Day 70

- 周复盘。
- 整理最终项目README、演示脚本、录屏。
- 面试训练：用STAR法讲3个bug。
- 产出：综合项目v0.8。

## 第11周：面试专项和查漏补缺

目标：把知识变成面试能说清、能手写、能解释取舍的能力。

### Day 71

- C语言专项：指针、内存、宏、volatile、const、static、字节对齐。
- 手写20题。
- 整理高频问题答案。
- 产出：`interview/c.md`。

### Day 72

- MCU专项：中断、DMA、定时器、UART/I2C/SPI/CAN、低功耗、看门狗。
- 画每个外设的调试流程。
- 产出：`interview/mcu.md`。

### Day 73

- RTOS专项：任务调度、同步、优先级反转、死锁、栈溢出、消息队列。
- 手写生产者消费者伪代码。
- 产出：`interview/rtos.md`。

### Day 74

- Linux专项：进程线程、IPC、socket、select/poll/epoll、串口、systemd。
- 手写多线程队列和TCP服务伪代码。
- 产出：`interview/linux.md`。

### Day 75

- 网络和协议专项：TCP三次握手、粘包、MQTT、Modbus、CRC、重传、心跳。
- 画协议解析状态机。
- 产出：`interview/protocol.md`。

### Day 76

- 项目专项：准备4个项目的讲解稿。
- 每个项目按：背景、目标、架构、难点、bug、优化、结果。
- 录音自测，控制在5分钟内。
- 产出：`interview/projects.md`。

### Day 77

- 模拟一面：基础知识和手写代码。
- 模拟二面：项目深挖和系统设计。
- 模拟HR面：转行原因、稳定性、薪资、地域。
- 产出：面试复盘。

## 第12周：投递、简历、最终打磨

目标：开始真实投递，形成面试反馈闭环。

### Day 78

- 写嵌入式软件简历。
- 项目经历用数据说话：协议、稳定性、测试次数、工具链。
- 删除空泛描述，突出C/Linux/RTOS/协议/调试。
- 产出：简历v1。

### Day 79

- 优化GitHub/Gitee首页。
- 每个项目补齐README、截图、架构图、演示视频链接。
- 确保别人能按文档跑起来。
- 产出：作品集主页。

### Day 80

- 对科大讯飞岗位定制简历。
- 梳理岗位关键词和项目匹配点。
- 写一封简短自荐信。
- 产出：讯飞版简历。

### Day 81

- 开始投递：科大讯飞、合肥/南京/上海/杭州嵌入式软件岗、物联网岗、Linux应用岗。
- 每投一个岗位记录JD关键词、投递版本、反馈。
- 产出：投递表。

### Day 82

- 根据真实JD查漏补缺。
- 针对缺口做2小时快速学习和1个demo。
- 重点补：C++11、Linux、RTOS、CAN、音频/AI边缘设备相关。
- 产出：补缺记录。

### Day 83

- 做完整模拟面试。
- 复盘表达问题：是否说清楚架构、权衡、定位过程。
- 修改简历和项目文档。
- 产出：简历v2。

### Day 84

- 总复盘。
- 列出继续提升路线：驱动、内核、音频、AI推理、产品化。
- 准备未来30天计划。
- 产出：最终作品集、投递包、面试题库。

## 每周验收标准

- 第1周：能熟练写C模块、Makefile、gdb调试。
- 第2周：纯C协议解析器可运行，有测试。
- 第3周：STM32基础外设可独立开发和调试。
- 第4周：FreeRTOS多任务项目可运行。
- 第5周：Modbus/RS485/可靠性机制完成。
- 第6周：ESP32联网、MQTT、配置、OTA跑通。
- 第7周：Linux C多线程、串口、socket、IPC掌握。
- 第8周：Linux边缘服务可部署运行。
- 第9周：交叉编译、启动流程、设备树、驱动概念能讲清。
- 第10周：综合项目联调完成，有压力测试。
- 第11周：面试知识库完成，能讲项目。
- 第12周：简历、作品集、投递闭环完成。

## 每周必须写的文档

- `weekly/weekXX_review.md`
- 本周完成了什么。
- 哪些bug最难，如何定位。
- 哪些知识点还不懂。
- 下周优先级。
- 本周项目截图、日志或视频。

## 面试项目讲解模板

每个项目都按下面顺序讲：

1. 项目背景：解决什么问题。
2. 系统架构：有哪些模块，数据怎么流动。
3. 你的职责：哪些代码是你写的。
4. 技术难点：协议解析、RTOS任务划分、断线重连、稳定性。
5. 关键bug：现象、定位过程、根因、修复。
6. 工程质量：测试、日志、文档、部署。
7. 结果：运行时长、测试次数、资源占用、演示效果。

## 每天不要做的事

- 不刷长视频式课程超过2小时。
- 不只看不写。
- 不把时间耗在换开发板、换IDE、换教程。
- 不跳过文档和测试。
- 不写没有README的项目。
- 不沉迷底层内核，先保证岗位高频能力闭环。

## 继续冲高级的后续路线

3个月后，如果已经拿到面试或offer，继续补：

- C++11/14工程化：RAII、智能指针、STL、线程库。
- Linux驱动：字符设备、platform、I2C/SPI/UART驱动、设备树。
- Bootloader和OTA：U-Boot、分区、回滚、签名。
- 音频方向：ALSA、I2S、麦克风阵列、回声消除基础。
- AI边缘方向：TFLite/MNN/ONNX Runtime、模型量化、NPU SDK。
- 产品化：日志系统、故障恢复、远程诊断、灰度升级、CI/CD。

## 最小成功标准

如果时间崩了，至少完成下面5件事：

1. 纯C协议解析器，带测试。
2. STM32 + FreeRTOS + UART/Modbus项目。
3. Linux C串口采集 + MQTT上报服务。
4. 一份嵌入式简历和4页项目讲解稿。
5. 100道高频面试题手写答案。
