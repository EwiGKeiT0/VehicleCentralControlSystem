#include "mediawidget.h"
#include "ui_mediawidget.h"

#define PHOTOTIME 2*1000

int TabController=2;//0:Navi,1:Browser,2:Index,3:Chat,4:Media,5:Setting
bool musicPlayOrPause;
bool videoPlayOrPause;
bool photoPlayOrPause;
QString mediaUrl=""; //文件路径
int mediaMode=0; //播放模式，0:音乐,1:视频,2:图片
QString mediaUrls[2005];
int playListContent=0;
void mediaWidget::onSearch(const QString &url){
    startStream(url);
}
mediaWidget::mediaWidget(QWidget *parent,Widget *father)
    : QWidget(parent)
    , ui(new Ui::mediaWidget)
    ,mainWindow(father)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:rgba(36,36,42,1)");
    this->setFixedSize(1110,700);

    if(ui->flowRenderer) {
        ui->flowRenderer->setMinimumSize(640, 480);
    }

    // 连接按钮信号与槽函数
    connect(ui->flowStart, &QPushButton::clicked, this, [=]() {
        startStream(ui->flowInput->text());
    });
    connect(ui->flowStop, &QPushButton::clicked, this, &mediaWidget::stopStream);
    //上边栏
    ui->backButton->setGeometry(40,90,50,50);
    ui->backButton->setPixmap(QPixmap(":/icons/inBack.png"));
    ui->backButton->setScaledContents(true);
    ui->backButton->setFixedSize(50,50);
    ui->backButton->installEventFilter(this);

    ui->NameText->setGeometry(110,82,500,50);
    ui->NameText->setStyleSheet("font-size:28px;color:rgba(255,255,255,1)");

    ui->InfoText->setGeometry(110,135,500,30);
    ui->InfoText->setStyleSheet("font-size:15px;color:rgba(255,255,255,1)");

    //播放键
    player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);  // 创建 QAudioOutput 对象

    player->setAudioOutput(audioOutput);  // 将音频输出设置为 audioOutput
    audioOutput->setVolume(0.5);  // 设置音量（范围是 0.0 到 1.0）

    player->setSource(QUrl::fromLocalFile(mediaUrl));  // 替换为你的音乐文件路径
    player->play();
    connect(player, &QMediaPlayer::metaDataChanged, this, &mediaWidget::updateAlbumArt);

    ui->leftButton->setGeometry(200,620,70,70);
    ui->leftButton->setScaledContents(true);
    ui->leftButton->setFixedSize(70,70);
    ui->leftButton->setStyleSheet("background-color:rgba(14, 14, 19, 0.54);border-radius:35");
    ui->leftButton->installEventFilter(this);

    QSvgRenderer* svgRender1 = new QSvgRenderer;
    svgRender1->load(QString(":/icons/leftIcon.svg"));
    QSize size1 = svgRender1->defaultSize(); //获取svg的大小
    QPixmap pix1(size1 * 1.8);          // 在这给绘图设备重新设置大小
    pix1.fill(Qt::transparent);        // 像素清空,这一步必须有,否则背景有黑框
    QPainter painter1(&pix1);           // 画家和绘图设备建立联系
    painter1.setRenderHints(QPainter::Antialiasing);     //反锯齿绘制
    svgRender1->render(&painter1);    //执行渲染操作

    ui->leftButton->setPixmap(pix1);   //将pix加载到QLabel上
    ui->leftButton->setAlignment(Qt::AlignCenter);  //设置居中显示

    ui->playButton->setGeometry(470,620,70,70);
    ui->playButton->setFixedSize(70,70);
    ui->playButton->setStyleSheet("background-color:rgba(14, 14, 19, 0.54);border-radius:35");
    ui->playButton->setPixmap(QPixmap(":/icons/pauseIcon.png").scaled(36,36, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->playButton->setAlignment(Qt::AlignCenter);
    ui->playButton->installEventFilter(this);

    ui->rightButton->setGeometry(770,620,70,70);
    ui->rightButton->setScaledContents(true);
    ui->rightButton->setFixedSize(70,70);
    ui->rightButton->setStyleSheet("background-color:rgba(14, 14, 19, 0.54);border-radius:35");

    QSvgRenderer* svgRender2 = new QSvgRenderer;
    svgRender2->load(QString(":/icons/rightIcon.svg"));
    QSize size2 = svgRender2->defaultSize(); //获取svg的大小
    QPixmap pix2(size2 * 1.8);          // 在这给绘图设备重新设置大小
    pix2.fill(Qt::transparent);        // 像素清空,这一步必须有,否则背景有黑框
    QPainter painter2(&pix2);           // 画家和绘图设备建立联系
    painter2.setRenderHints(QPainter::Antialiasing);     //反锯齿绘制
    svgRender2->render(&painter2);    //执行渲染操作

    ui->rightButton->setPixmap(pix2);   //将pix加载到QLabel上
    ui->rightButton->setAlignment(Qt::AlignCenter);  //设置居中显示
    ui->rightButton->installEventFilter(this);

    //专辑封面ui
    ui->albumCoverLabel = new QLabel(this);
    ui->albumCoverLabel->setGeometry(350,160,70,70);
    ui->albumCoverLabel->setFixedSize(400, 400);  // 设置封面显示的大小
    ui->albumCoverLabel->setStyleSheet("background-color: rgba(0, 0, 0, 0.5);");
    //ui->albumCoverLabel->move(100, 100);  // 设置封面显示的位置
    ui->albumCoverLabel->setAlignment(Qt::AlignCenter);


    //视频播放
    videoWidget = new QVideoWidget(this);
    videoWidget->setFixedSize(510, 480);  // 设置视频窗口大小
    videoWidget->setGeometry(80,90,640, 480);




    //图片轮播
    timer = new QTimer;

    timer->setInterval(PHOTOTIME);
    timer->start();
    ui->photoLabel->setGeometry(220,130,70,70);
    ui->photoLabel->setFixedSize(640, 480);
    ui->photoLabel->setScaledContents(true);
    connect(timer,&QTimer::timeout,this,[=](){
        if(ui->listWidget->currentItem()!=NULL&&mediaMode==2){
            int index=ui->listWidget->row(ui->listWidget->currentItem());
            if(index==playListContent-1){//若为最后一首歌曲
                ui->listWidget->setCurrentItem(ui->listWidget->item(0));
                this->on_listWidget_itemClicked(ui->listWidget->item(0));
            }
            else {
                ui->listWidget->setCurrentItem(ui->listWidget->item(index+1));
                this->on_listWidget_itemClicked(ui->listWidget->item(index+1));
            }
        }
    });

    //文件管理器
    ui->addFileButton->setGeometry(870,510,200,50);
    ui->addFileButton->setStyleSheet("background-color: rgba(255, 255, 255, 0.5);");
    ui->addFileButton->installEventFilter(this);

    //隐藏控件
    videoWidget->hide();
    ui->leftButton->hide();
    ui->playButton->hide();
    ui->rightButton->hide();
    ui->photoLabel->hide();
    ui->albumCoverLabel->hide();
    ui->addFileButton->hide();
    ui->NameText->hide();
    ui->InfoText->hide();
    ui->listWidget->hide();
    ui->backButton->hide();
    ui->flowStart->hide();
    ui->flowStop->hide();
    ui->flowRenderer->hide();
    ui->flowInput->hide();

    //多媒体选择页面
    ui->musicEntry->setGeometry(100,300,200,200);
    ui->musicEntry->setPixmap(QPixmap(":/icons/musicEntry.png"));
    ui->musicEntry->setScaledContents(true);
    ui->musicEntry->installEventFilter(this);

    ui->videoEntry->setGeometry(400,300,200,200);
    ui->videoEntry->setPixmap(QPixmap(":/icons/videoEntry.png"));
    ui->videoEntry->setScaledContents(true);
    ui->videoEntry->installEventFilter(this);

    ui->pictureEntry->setGeometry(700,300,200,200);
    ui->pictureEntry->setPixmap(QPixmap(":/icons/pictureEntry.png"));
    ui->pictureEntry->setScaledContents(true);
    ui->pictureEntry->installEventFilter(this);

    ui->flowEntry->setGeometry(425,550,150,150);
    ui->flowEntry->setPixmap(QPixmap(":/icons/flowEntry.png"));
    ui->flowEntry->setScaledContents(true);
    ui->flowEntry->installEventFilter(this);

    ui->flowRenderer->setGeometry(100,150,640, 480);
    ui->flowInput->setGeometry(800,460,150,30);
    ui->flowStart->setGeometry(800,510,100,30);
    ui->flowStop->setGeometry(800,560,100,30);

    ui->flowStart->setStyleSheet("background-color: rgba(150, 150, 150, 0.5);");
    ui->flowStop->setStyleSheet("background-color: rgba(150, 150, 150, 0.5);");
    ui->flowInput->setStyleSheet("background-color: rgba(150, 150, 150, 0.5);");


    //播放列表样式
    ui->listWidget->setStyleSheet(
        "QListWidget {"
        "    height:100;"
        "    background-color: rgba(150, 150, 150, 0.5);"  // 背景色
        "    border: 1px solid rgba(0, 0, 0, 1);"  // 边框
        "}"

        // 设置每个 QListWidgetItem 的样式
        "QListWidget::item {"
        "    padding: 10px;"  // 内边距
        "    border-bottom: 1px solid #c0c0c0;"  // 每个项的下边框
        "}"

        // 鼠标悬停时的样式
        "QListWidget::item:hover {"
        "    background-color: #d0d0d0;"  // 背景色变化
        "}"

        // 选中状态的样式
        "QListWidget::item:selected {"
        "    background-color: #a0a0a0;"  // 选中的背景色
        "    color: white;"  // 选中的文字颜色
        "}"
        );
    ui->listWidget->move(870,50);
    ui->listWidget->setGeometry(870,160,200,350);


}

mediaWidget::~mediaWidget()
{
    delete ui;
}
bool mediaWidget::eventFilter(QObject *obj, QEvent *event)
{
    //播放/暂停
    if(qobject_cast<QLabel*>(obj) == ui->playButton && event->type() == QEvent::MouseButtonRelease)
    {
        switch (mediaMode) {
        case 0:
            //现在是音乐播放状态，仅控制音乐播放
            if(musicPlayOrPause){
                ui->playButton->setPixmap(QPixmap(":/icons/pauseIcon.png").scaled(36,36, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                ui->playButton->setAlignment(Qt::AlignCenter);
                musicPlayOrPause=!musicPlayOrPause;
                player->play();
            }
            else{
                QSvgRenderer* svgRender1 = new QSvgRenderer;
                svgRender1->load(QString(":/icons/playIcon.svg"));
                QSize size1 = svgRender1->defaultSize(); //获取svg的大小
                QPixmap pix1(size1 * 2.5);          // 在这给绘图设备重新设置大小
                pix1.fill(Qt::transparent);        // 像素清空,这一步必须有,否则背景有黑框
                QPainter painter1(&pix1);           // 画家和绘图设备建立联系
                painter1.setRenderHints(QPainter::Antialiasing);     //反锯齿绘制
                svgRender1->render(&painter1);    //执行渲染操作
                ui->playButton->setPixmap(pix1);   //将pix加载到QLabel上
                ui->playButton->setAlignment(Qt::AlignCenter);  //设置居中显示
                musicPlayOrPause=!musicPlayOrPause;
                player->pause();
            }
            break;
        case 1:
            //现在是视频播放状态，仅控制视频播放
            if(videoPlayOrPause){
                ui->playButton->setPixmap(QPixmap(":/icons/pauseIcon.png").scaled(36,36, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                ui->playButton->setAlignment(Qt::AlignCenter);
                videoPlayOrPause=!videoPlayOrPause;
                videoPlayer->play();
            }
            else{
                QSvgRenderer* svgRender1 = new QSvgRenderer;
                svgRender1->load(QString(":/icons/playIcon.svg"));
                QSize size1 = svgRender1->defaultSize(); //获取svg的大小
                QPixmap pix1(size1 * 2.5);          // 在这给绘图设备重新设置大小
                pix1.fill(Qt::transparent);        // 像素清空,这一步必须有,否则背景有黑框
                QPainter painter1(&pix1);           // 画家和绘图设备建立联系
                painter1.setRenderHints(QPainter::Antialiasing);     //反锯齿绘制
                svgRender1->render(&painter1);    //执行渲染操作
                ui->playButton->setPixmap(pix1);   //将pix加载到QLabel上
                ui->playButton->setAlignment(Qt::AlignCenter);  //设置居中显示
                videoPlayOrPause=!videoPlayOrPause;
                videoPlayer->pause();
            }
            break;
        case 2:
            //现在是图片播放状态，仅控制图片播放
            if(photoPlayOrPause){
                ui->playButton->setPixmap(QPixmap(":/icons/pauseIcon.png").scaled(36,36, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                ui->playButton->setAlignment(Qt::AlignCenter);
                photoPlayOrPause=!photoPlayOrPause;
                timer->start(PHOTOTIME);
            }
            else{
                QSvgRenderer* svgRender1 = new QSvgRenderer;
                svgRender1->load(QString(":/icons/playIcon.svg"));
                QSize size1 = svgRender1->defaultSize(); //获取svg的大小
                QPixmap pix1(size1 * 2.5);          // 在这给绘图设备重新设置大小
                pix1.fill(Qt::transparent);        // 像素清空,这一步必须有,否则背景有黑框
                QPainter painter1(&pix1);           // 画家和绘图设备建立联系
                painter1.setRenderHints(QPainter::Antialiasing);     //反锯齿绘制
                svgRender1->render(&painter1);    //执行渲染操作
                ui->playButton->setPixmap(pix1);   //将pix加载到QLabel上
                ui->playButton->setAlignment(Qt::AlignCenter);  //设置居中显示
                photoPlayOrPause=!photoPlayOrPause;
                timer->stop();
            }
            break;
        }

    }

    //上一个
    if(qobject_cast<QLabel*>(obj) == ui->leftButton && event->type() == QEvent::MouseButtonRelease){
        if(ui->listWidget->currentItem()!=NULL){
            int index=ui->listWidget->row(ui->listWidget->currentItem());
            qDebug()<<"正在播放"<<index;
            qDebug()<<"playListContent = "<<playListContent;
            if(index==0){//若为第一首歌曲
                ui->listWidget->setCurrentItem(ui->listWidget->item(playListContent-1));
                this->on_listWidget_itemClicked(ui->listWidget->item(playListContent-1));
            }
            else {
                ui->listWidget->setCurrentItem(ui->listWidget->item(index-1));
                this->on_listWidget_itemClicked(ui->listWidget->item(index-1));
            }
        }
    }
    //下一个
    if(qobject_cast<QLabel*>(obj) == ui->rightButton && event->type() == QEvent::MouseButtonRelease){
        if(ui->listWidget->currentItem()!=NULL){
            int index=ui->listWidget->row(ui->listWidget->currentItem());
            if(index==playListContent-1){//若为最后一首歌曲
                ui->listWidget->setCurrentItem(ui->listWidget->item(0));
                this->on_listWidget_itemClicked(ui->listWidget->item(0));
            }
            else {
                ui->listWidget->setCurrentItem(ui->listWidget->item(index+1));
                this->on_listWidget_itemClicked(ui->listWidget->item(index+1));
            }
        }
    }
    //添加进播放列表
    if(qobject_cast<QLabel*>(obj) == ui->addFileButton && event->type() == QEvent::MouseButtonRelease){
        if(mediaMode==0){
            mediaUrl=QFileDialog::getOpenFileName(this,"请选择文件","/home","*.mp3 *.ogg *.wav");
            QFile musicPlayList("../../musicPlayList.txt");
            if(!musicPlayList.open(QIODevice::ReadWrite | QIODevice::Append))   //以读写且追加的方式写入文本
            {
                qDebug() << ("打开文件失败");
            }
            else{
                mediaUrls[playListContent]=mediaUrl;
                playListContent++;
                QFileInfo fileInfo(mediaUrl);
                //更新名称信息
                ui->listWidget->addItem(QString(fileInfo.baseName()).split("-")[1]);
                ui->NameText->setText(QString(fileInfo.baseName()).split("-")[1]);
                ui->InfoText->setText(QString(fileInfo.baseName()).split("-")[0]);
            }
            qDebug() << ("成功了（大概？）");
            QTextStream txtOutput(&musicPlayList);
            txtOutput << mediaUrl+"\n";
            musicPlayList.close();
            ui->listWidget->setCurrentItem(ui->listWidget->item(playListContent-1));
            //启动player
            player->setSource(QUrl::fromLocalFile(mediaUrl));
            player->play();
        }
        if(mediaMode==1){
            qDebug()<<"??????????/";
            mediaUrl=QFileDialog::getOpenFileName(this,"请选择文件","/home","*.mp4");
            qDebug()<<mediaUrl<<"6666666666666666";
            QFile videoPlayList("../../videoPlayList.txt");
            if(!videoPlayList.open(QIODevice::ReadWrite | QIODevice::Append))   //以读写且追加的方式写入文本
            {
                qDebug() << ("打开文件失败");
            }
            else{
                mediaUrls[playListContent]=mediaUrl;
                playListContent++;
                QFileInfo fileInfo(mediaUrl);
                //更新名称信息
                ui->listWidget->addItem(QString(fileInfo.baseName()));
                ui->NameText->setText(QString(fileInfo.baseName()));
            }
            qDebug() << ("成功了（大概？）");
            QTextStream txtOutput(&videoPlayList);
            txtOutput << mediaUrl+"\n";
            videoPlayList.close();
            ui->listWidget->setCurrentItem(ui->listWidget->item(playListContent-1));
            //启动player
            qDebug()<<mediaUrl<<"6666666666666666";
            videoPlayer->setSource(QUrl::fromLocalFile(mediaUrl));
            videoPlayer->play();
        }
        if(mediaMode==2){
            mediaUrl=QFileDialog::getOpenFileName(this,"请选择文件","/home","*.png *.jpg");
            QFile videoPlayList("../../picturePlayList.txt");
            if(!videoPlayList.open(QIODevice::ReadWrite | QIODevice::Append))   //以读写且追加的方式写入文本
            {
                qDebug() << ("打开文件失败");
            }
            else{
                mediaUrls[playListContent]=mediaUrl;
                playListContent++;
                QFileInfo fileInfo(mediaUrl);
                //更新名称信息
                ui->listWidget->addItem(QString(fileInfo.baseName()));
                ui->NameText->setText(QString(fileInfo.baseName()));
            }
            qDebug() << ("成功了（大概？）");
            QTextStream txtOutput(&videoPlayList);
            txtOutput << mediaUrl+"\n";
            videoPlayList.close();
            ui->listWidget->setCurrentItem(ui->listWidget->item(playListContent-1));
            QImage img;
            img.load(mediaUrl);
            ui->photoLabel->setPixmap(QPixmap::fromImage(img));
        }
    }

    //切换到音乐模式
    if(qobject_cast<QLabel*>(obj) == ui->musicEntry && event->type() == QEvent::MouseButtonRelease){
        mediaMode=0;//切换mode
        ui->leftButton->show();
        ui->playButton->show();
        ui->rightButton->show();
        ui->albumCoverLabel->show();
        ui->NameText->show();
        ui->InfoText->show();
        ui->addFileButton->show();
        ui->listWidget->show();
        ui->backButton->show();

        ui->musicEntry->hide();
        ui->pictureEntry->hide();
        ui->videoEntry->hide();
        ui->flowEntry->hide();

        //初始化播放列表
        QFile file(":/playList/musicPlayList.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QString line;
            QTextStream in(&file);  //用文件构造流
            line = in.readLine();//读取一行放到字符串里
            qDebug() << line;
            playListContent = 0;
            while(!line.isNull())//字符串有内容
            {
                mediaUrls[playListContent]=QString(line);//初始化url数组
                playListContent++;
                QFile temp(line);
                if(temp.exists()){//维护url数组，防止读取串行
                    QFileInfo fileInfo(line);
                    ui->listWidget->addItem(QString(fileInfo.baseName()).split("-")[1]);
                }
                else{
                    playListContent--;
                    mediaUrls[playListContent]=NULL;
                }
                line=in.readLine();//循环读取下行
            }

        }
        file.close();
    }
    //切换到视频模式
    if(qobject_cast<QLabel*>(obj) == ui->videoEntry && event->type() == QEvent::MouseButtonRelease){
        qDebug()<<"shipinshipin";
        mediaMode=1;//切换mode
        ui->backButton->show();
        ui->leftButton->show();
        ui->playButton->show();
        ui->rightButton->show();
        ui->addFileButton->show();
        ui->listWidget->show();
        // 自动播放视频
        videoWidget->show();


        // 创建 QMediaPlayer 对象
        videoPlayer = new QMediaPlayer(this);
        videoPlayer->setVideoOutput(videoWidget);

        // 设置媒体资源
        videoPlayer->setSource(QUrl::fromLocalFile("C:\\Users\\86153\\Desktop\\resources\\video_preview_h264.mp4"));  // 替换为你的视频文件路径
        videoPlayer->play();
        ui->NameText->show();
        ui->InfoText->show();

        ui->musicEntry->hide();
        ui->pictureEntry->hide();
        ui->videoEntry->hide();
        ui->flowEntry->hide();

        //初始化播放列表
        QFile file(":/playList/videoPlayList.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QString line;
            QTextStream in(&file);  //用文件构造流
            line = in.readLine();//读取一行放到字符串里
            qDebug() << line;
            playListContent = 0;
            while(!line.isNull())//字符串有内容
            {
                mediaUrls[playListContent]=QString(line);//初始化url数组
                playListContent++;
                QFile temp(line);
                if(temp.exists()){//维护url数组，防止读取串行
                    QFileInfo fileInfo(line);
                    ui->listWidget->addItem(QString(fileInfo.baseName()));
                }
                else{
                    playListContent--;
                    mediaUrls[playListContent]=NULL;
                }
                line=in.readLine();//循环读取下行
            }

        }
        file.close();
    }
    //切换到图片模式
    if(qobject_cast<QLabel*>(obj) == ui->pictureEntry && event->type() == QEvent::MouseButtonRelease){
        mediaMode=2;//切换mode
        ui->backButton->show();
        ui->leftButton->show();
        ui->playButton->show();
        ui->rightButton->show();
        ui->photoLabel->show();
        ui->NameText->show();
        ui->InfoText->show();
        ui->addFileButton->show();
        ui->listWidget->show();

        ui->musicEntry->hide();
        ui->pictureEntry->hide();
        ui->videoEntry->hide();
        ui->flowEntry->hide();
        //初始化播放列表
        QFile file(":/playList/picturePlayList.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QString line;
            QTextStream in(&file);  //用文件构造流
            line = in.readLine();//读取一行放到字符串里
            qDebug() << line;
            playListContent = 0;
            while(!line.isNull())//字符串有内容
            {
                mediaUrls[playListContent]=QString(line);//初始化url数组
                playListContent++;
                QFile temp(line);
                if(temp.exists()){//维护url数组，防止读取串行
                    QFileInfo fileInfo(line);
                    ui->listWidget->addItem(QString(fileInfo.baseName()));
                }
                else{
                    playListContent--;
                    mediaUrls[playListContent]=NULL;
                }
                line=in.readLine();//循环读取下行
            }

        }
        file.close();
    }
    //返回键
    if(qobject_cast<QLabel*>(obj) == ui->backButton && event->type() == QEvent::MouseButtonRelease){
        //隐藏控件
        videoWidget->hide();
        ui->leftButton->hide();
        ui->playButton->hide();
        ui->rightButton->hide();
        ui->photoLabel->hide();
        ui->albumCoverLabel->hide();
        ui->addFileButton->hide();
        ui->NameText->hide();
        ui->InfoText->hide();
        ui->listWidget->hide();
        ui->listWidget->clear();
        ui->backButton->hide();
        ui->flowStart->hide();
        ui->flowStop->hide();
        ui->flowRenderer->hide();
        ui->flowInput->hide();

        //显示三个按钮
        ui->musicEntry->show();
        ui->videoEntry->show();
        ui->pictureEntry->show();
        ui->flowEntry->show();
        playListContent=0;
    }
    //流媒体入口
    if(qobject_cast<QLabel*>(obj) == ui->flowEntry && event->type() == QEvent::MouseButtonRelease){
        mediaMode=3;//切换mode

        ui->musicEntry->hide();
        ui->pictureEntry->hide();
        ui->videoEntry->hide();
        ui->flowEntry->hide();

        ui->backButton->show();
        ui->flowStart->show();
        ui->flowStop->show();
        ui->flowRenderer->show();
        ui->flowInput->show();
    }
    return false;
}

//更新专辑封面
void mediaWidget::updateAlbumArt()
{
    QVariant albumArtVariant = player->metaData().value(QMediaMetaData::ThumbnailImage);
    qDebug() << "Album art variant is valid:" << albumArtVariant.isValid();
    QImage albumArt = albumArtVariant.value<QImage>();
    qDebug() << "Album art is null:" << albumArt.isNull();

    if (!albumArt.isNull()) {
        ui->albumCoverLabel->setPixmap(QPixmap::fromImage(albumArt).scaled(ui->albumCoverLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        // Optional: Set a default image if no album art is found
        ui->albumCoverLabel->clear();  // or set a default pixmap
    }
}

//点击播放列表中的元素
void mediaWidget::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(mediaMode==0){
        player->setSource(QUrl::fromLocalFile(mediaUrls[ui->listWidget->row(item)]));
        qDebug()<<mediaUrls[ui->listWidget->row(item)];
        //更新名称信息
        QFileInfo fileInfo(mediaUrls[ui->listWidget->row(item)]);
        ui->NameText->setText(QString(fileInfo.baseName()).split("-")[1]);
        ui->InfoText->setText(QString(fileInfo.baseName()).split("-")[0]);
        player->play();
    }
    if(mediaMode==1){
        videoPlayer->setSource(QUrl::fromLocalFile(mediaUrls[ui->listWidget->row(item)]));
        qDebug()<<mediaUrls[ui->listWidget->row(item)];
        //更新名称信息
        QFileInfo fileInfo(mediaUrls[ui->listWidget->row(item)]);
        ui->NameText->setText(QString(fileInfo.baseName()));
        videoPlayer->play();
        qDebug()<<"playplayplay";
    }
    if(mediaMode==2){
        QImage img;
        QFileInfo fileInfo(mediaUrls[ui->listWidget->row(item)]);
        img.load(mediaUrls[ui->listWidget->row(item)]);
        ui->photoLabel->setPixmap(QPixmap::fromImage(img));
    }
}
void mediaWidget::startStream(const QString &url) {

    // if (streamThread || audioStreamThread) {
    //     stopStream();  // 如果有播放中的流，先停止
    // }
    qDebug()<<"444444444444"<<url;
    // 启动视频流线程
    streamThread = new StreamThread(url, this);
    qDebug()<<"kaishibofang!";
    connect(streamThread, &StreamThread::finished, streamThread, &QObject::deleteLater);
    connect(streamThread, &StreamThread::frameReady, this, &mediaWidget::onFrameReady);
    streamThread->start();

    // 启动音频流线程
    audioStreamThread = new AudioStreamThread(url, this);
    connect(audioStreamThread, &AudioStreamThread::finished, audioStreamThread, &QObject::deleteLater);
    connect(audioStreamThread, &AudioStreamThread::errorOccurred, this, &mediaWidget::onErrorOccurred);
    audioStreamThread->start();
}

void mediaWidget::stopStream() {
    if (streamThread) {
        streamThread->stop();
        streamThread->wait();  // 等待线程结束
        streamThread = nullptr;
    }

    if (audioStreamThread) {
        audioStreamThread->stop();
        audioStreamThread->wait();  // 等待线程结束
        audioStreamThread = nullptr;
    }
}

void mediaWidget::onFrameReady(const QImage &image) {
    if(ui->flowRenderer) {
        ui->flowRenderer->setPixmap(QPixmap::fromImage(image));
    }
}

void mediaWidget::onErrorOccurred(const QString &error) {
    qDebug() << "Error occurred:" << error;
    stopStream(); // 如果发生错误，停止流
}
