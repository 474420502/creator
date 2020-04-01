#ifndef __CREATOR__H__
#define __CREATOR__H__

#include <iostream>
#include <random>
#include <memory>
#include <string>

using std::wstring;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::uniform_int_distribution, std::uniform_real_distribution;
using std::random_device;
using std::shared_ptr, std::make_shared;

random_device __rd;

template<class T>
class creator;

template<class T>
class number_creator;

template<class T>
class real_creator;

template<class T>
class name_creator;



template<class T>
class creator {
public:

    creator(){};
    ~creator(){};

    virtual T create() {};

    static
    shared_ptr<creator<T>>  make_number_creator(T min, T max) {
        shared_ptr<number_creator<T>> nc =  make_shared<number_creator<T>>();
        nc->engine = default_random_engine(__rd());
        nc->distribution = uniform_int_distribution<T>(min, max);
        return nc;
    }

  /**
   *  make_real_creator.
   *  params(0.0, 1.0). only support float double
   *  number in the range [0, 1).
   */
    static
    shared_ptr<creator<T>>  make_real_creator(T min, T max) {
        shared_ptr<real_creator<T>> rc =  make_shared<real_creator<T>>();
        rc->engine = default_random_engine(__rd());
        rc->distribution = uniform_real_distribution<T>(min, max);
        return rc;
    }

        static
    shared_ptr<creator<T>>  make_name_creator() {
        shared_ptr<name_creator<T>> rc =  make_shared<name_creator<T>>();
        rc->engine = default_random_engine(__rd());
        return rc;
    }
};


template<class T>
class number_creator:public creator<T> {
public:

    // number_creator(){};
    // number_creator(number_creator *other) {
    //     engine = other->engine;
    //     distribution = other->distribution;
    // }

    default_random_engine engine; 
    uniform_int_distribution<T> distribution;

    T create() override {
        return distribution(engine);
    }
};

template<class T>
class real_creator :public creator<T> {
public:

    default_random_engine engine; 
    uniform_real_distribution<T> distribution;

    T create() override {
        return distribution(engine);
    }
};

const wstring first_name_array = L"赵 钱 孙 李 周 吴 郑 王 冯 陈 褚 卫 蒋 沈 韩 杨 朱 秦 尤 许 何 吕 施 张 孔 曹 严 华 金 魏 陶 姜 戚 谢 邹 喻 柏 水 窦 章 云 苏 潘 葛 奚 范 彭 郎 鲁 韦 昌 马 苗 凤 花 方 俞 任 袁 柳 酆 鲍 史 唐 费 廉 岑 薛 雷 贺 倪 汤 滕 殷 罗 毕 郝 邬 安 常 乐 于 时 傅 皮 卞 齐 康 伍 余 元 卜 顾 孟 平 黄 和 穆 萧 尹 姚 邵 湛 汪 祁 毛 禹 狄 米 贝 明 臧 计 伏 成 戴 谈 宋 茅 庞 熊 纪 舒 屈 项 祝 董 梁 杜 阮 蓝 闵 席 季 麻 强 贾 路 娄 危 江 童 颜 郭 梅 盛 林 刁 钟 徐 邱 骆 高 夏 蔡 田 樊 胡 凌 霍 虞 万 支 柯 昝 管 卢 莫 经 房 裘 缪 干 解 应 宗 丁 宣 贲 邓 郁 单 杭 洪 包 诸 左 石 崔 吉 钮 龚 程 嵇 邢 滑 裴 陆 荣 翁 荀 羊 於 惠 甄 曲 家 封 芮 羿 储 靳 汲 邴 糜 松 井 段 富 巫 乌 焦 巴 弓 牧 隗 山 谷 车 侯 宓 蓬 全 郗 班 仰 秋 仲 伊 宫 宁 仇 栾 暴 甘 钭 厉 戎 祖 武 符 刘 景 詹 束 龙 叶 幸 司 韶 郜 黎 蓟 薄 印 宿 白 怀 蒲 台 从 鄂 索 咸 籍 赖 卓 蔺 屠 蒙 池 乔 阴 欎 胥 能 苍 双 闻 莘 党 翟 谭 贡 劳 逄 姬 申 扶 堵 冉 宰 郦 雍 郤 璩 桑 桂 濮 牛 寿 通 边 扈 燕 冀 郏 浦 尚 农 温 别 庄 晏 柴 瞿 阎 充 慕 连 茹 习 宦 艾 鱼 容 向 古 易 慎 戈 廖 庾 终 暨 居 衡 步 都 耿 满 弘 匡 国 文 寇 广 禄 阙 东 殴 殳 沃 利 蔚 越 夔 隆 师 巩 厍 聂 晁 勾 敖 融 冷 訾 辛 阚 那 简 饶 空 曾 毋 沙 乜 养 鞠 须 丰 巢 关 蒯 相 查 后 荆 红 游 竺 权 逯 盖 益 桓 公 万俟 司马 上官 欧阳 夏侯 诸葛 闻人 东方 赫连 皇甫 尉迟 公羊 澹台 公冶 宗政 濮阳 淳于 单于 太叔 申屠 公孙 仲孙 轩辕 令狐 钟离 宇文 长孙 慕容 鲜于 闾丘 司徒 司空 亓官 司寇 仉 督 子车 颛孙 端木 巫马 公西 漆雕 乐正 壤驷 公良 拓跋 夹谷 宰父 谷梁 晋 楚 闫 法 汝 鄢 涂 钦 段干 百里 东郭 南 门 呼延 归海 羊舌 微生 岳 帅 缑 亢 况 郈 有 琴 梁丘 左丘 东门 西门 商 牟 佘 佴 伯 赏 南宫 墨 哈 谯 笪 年 爱 阳 佟 第五 言 福 百 姓";

template<class T>
class name_creator :public creator<T> {
private:
    uniform_int_distribution<uint> distribution;
public:
    // wstring first_name_array;
    default_random_engine engine; 

    name_creator() {
        distribution = uniform_int_distribution<uint>(0, uint(first_name_array.size()));
    }

    T create() override {
        T result;
        result += first_name_array[distribution(engine)];
        return result;    
    }
};

#endif // !1