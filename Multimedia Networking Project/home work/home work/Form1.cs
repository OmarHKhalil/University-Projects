using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using Microsoft.VisualBasic;
using NAudio.Wave;
using static System.Net.Mime.MediaTypeNames;
//using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace home_work
{
    public partial class Form1 : Form
    {
        private readonly ToolTip tt = new ToolTip();
        private ToolStripItem _currentItem = null;

        public Form1()
        {
            InitializeComponent();

            // إعداد توقيتات ظهور/اختفاء التلميح
            tt.InitialDelay = 1000;   // يظهر بعد 1 ثانية
            tt.AutoPopDelay = 3000;   // يبقى 3 ثوانٍ
            tt.ReshowDelay = 500;
            tt.ShowAlways = true;

            // ربط أحداث المرور والخروج لكل عنصر
            inToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(inToolStripMenuItem, "Enlarge the image by 20%.");
            inToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            outToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(outToolStripMenuItem, "Reduce the image by 20 %.");
            outToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            fileToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(fileToolStripMenuItem, "Open and save images or audio files");
            fileToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            openToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(openToolStripMenuItem, "Open images");
            openToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            openAudioToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(openAudioToolStripMenuItem, "Open audio files");
            openAudioToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            saveImageToolStripMenuItem1.MouseEnter += (s, e) =>
                ShowItemToolTip(saveImageToolStripMenuItem1, "save images");
            saveImageToolStripMenuItem1.MouseLeave += (s, e) =>
                HideItemToolTip();
            //------------------
            editToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(editToolStripMenuItem, "Some Image editing operations");
            editToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            infoToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(infoToolStripMenuItem, "Some information about the image.");
            infoToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            convertToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(convertToolStripMenuItem, "Image converting operations");
            convertToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            grayScaleToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(grayScaleToolStripMenuItem, "Convert the image to grayscale");
            grayScaleToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            addFilterToolStripMenuItem1.MouseEnter += (s, e) =>
                ShowItemToolTip(addFilterToolStripMenuItem1, "Extract Red color channel from the image");
            addFilterToolStripMenuItem1.MouseLeave += (s, e) =>
                HideItemToolTip();
            //-------------------
            rGBToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(rGBToolStripMenuItem, "Extract color channels from the image");
            rGBToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            colorRToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(colorRToolStripMenuItem, "Extract Red color channel from the image");
            colorRToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            colorGToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(colorGToolStripMenuItem, "Extract Green color channel from the image");
            colorGToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            colorBToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(colorBToolStripMenuItem, "Extract Blu color channel from the image");
            colorBToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            colorRGToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(colorRGToolStripMenuItem, "Extract Red and Green color channel from the image");
            colorRGToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            colorRBToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(colorRBToolStripMenuItem, "Extract Red and Blue color channel from the image");
            colorRBToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            colorGBToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(colorGBToolStripMenuItem, "Extract Green and Blue color channel from the image");
            colorGBToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            //-------------------
            drawToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(drawToolStripMenuItem, "Some Shape to draw on image");
            drawToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            drawRectangleToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(drawRectangleToolStripMenuItem, "Drawraw rectangle center on image.");
            drawRectangleToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            drawEllipsToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(drawEllipsToolStripMenuItem, "Draw ellips on image.");
            drawEllipsToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            drawTringleToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(drawTringleToolStripMenuItem, "Draw tringle on image.");
            drawTringleToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            drawCircleToolStripMenuItem1.MouseEnter += (s, e) =>
                ShowItemToolTip(drawCircleToolStripMenuItem1, "Draw circle on image.");
            drawCircleToolStripMenuItem1.MouseLeave += (s, e) =>
                HideItemToolTip();

            addTextToolStripMenuItem1.MouseEnter += (s, e) =>
                ShowItemToolTip(addTextToolStripMenuItem1, "Add text on image by mouse");
            addTextToolStripMenuItem1.MouseLeave += (s, e) =>
                HideItemToolTip();
            //------------------
            mix2imagesToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(mix2imagesToolStripMenuItem, "Mix tow image in one image.");
            mix2imagesToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            //------------------
            mix2imagesToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(zoomToolStripMenuItem, "Applt Zoom in/out on image");
            mix2imagesToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            //------------------
            manipulationToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(manipulationToolStripMenuItem, "Some manipulation to apply on image");
            manipulationToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();

            cropToolStripMenuItem1.MouseEnter += (s, e) =>
                ShowItemToolTip(cropToolStripMenuItem1, "Crop images by a part selected by the user with the mouse");
            cropToolStripMenuItem1.MouseLeave += (s, e) =>
                HideItemToolTip();
            rotateToolStripMenuItem1.MouseEnter += (s, e) =>
                ShowItemToolTip(rotateToolStripMenuItem1, "Rotate the image by a specific angle");
            rotateToolStripMenuItem1.MouseLeave += (s, e) =>
                HideItemToolTip();
            flipHToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(flipHToolStripMenuItem, "Flip the image horizontally");
            flipHToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            flipVToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(flipVToolStripMenuItem, "Flip the image vertically");
            flipVToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            flipBothToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(flipBothToolStripMenuItem, "Flip the image horizontally/vertically  ");
            flipBothToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            resizeToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(resizeToolStripMenuItem, "Resize the image to a specified width and height");
            resizeToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            //------------------
            undoToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(undoToolStripMenuItem, "Cancel the last action you performed to revert to the previous state.");
            undoToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
            undoToolStripMenuItem.MouseEnter += (s, e) =>
                ShowItemToolTip(redoToolStripMenuItem, "Redo the step you have undone.");
            undoToolStripMenuItem.MouseLeave += (s, e) =>
                HideItemToolTip();
        }

        private void ShowItemToolTip(ToolStripItem item, string text)
        {
            _currentItem = item;

            // حدد مالك العنصر (MenuStrip أو DropDown)
            var owner = item.Owner;
            if (owner == null) return;

            // احصل على موضع أسفل العنصر بالنسبة للمالك
            var rect = item.Bounds;
            var screenPoint = owner.PointToScreen(new Point(rect.Left, rect.Bottom));

            // حوّل الموضع إلى إحداثيات الفورم، واعرض التلميح هناك
            var clientPoint = this.PointToClient(screenPoint);
            tt.Show(text, this, clientPoint.X, clientPoint.Y, tt.AutoPopDelay);
        }

        private void HideItemToolTip()
        {
            _currentItem = null;
            tt.Hide(this);
        }

        // Audio
        WaveOut w;
        Mp3FileReader s;
        long value;
        // Picture
        Bitmap? b; // Current working image
        Bitmap? originalImage; // Always keeps the unmodified loaded image
        Bitmap? tempr;
        Stack<Bitmap> Undo = new Stack<Bitmap>();
        Stack<Bitmap> Redo = new Stack<Bitmap>();
        // Draw
        Color rectangleColor = Color.Red;
        bool fillRectangle = true;
        int mousex = 0;
        int mousey = 0;
        int drawing = 0;
        bool ismousedown = false;
        Bitmap previewImage = null;  // صورة مؤقتة للمعاينة
        Color currentColor = Color.Black;
        int lineWidth = 2;
        bool fillMode = true;
        Bitmap? currentUnfiltered;
        Bitmap? currentUnfiltered2;
        bool pickingColorFromImage;

        /* private void FlipHorizontal()
         {
             if (b == null) return;
             UndoStack();
             b.RotateFlip(RotateFlipType.RotateNoneFlipX);
             pictureBox2.Image = b;
         }

         private void FlipVertical()
         {
             if (b == null) return;
             UndoStack();
             b.RotateFlip(RotateFlipType.RotateNoneFlipY);
             pictureBox2.Image = b;
         }

         private void FlipBoth()
         {
             if (b == null) return;
             UndoStack();
             b.RotateFlip(RotateFlipType.RotateNoneFlipXY);
             pictureBox2.Image = b;
         }*/

        private bool AskShapeOptions()
        {
            DialogResult result = MessageBox.Show(
       "Press Yes to choose the color from the list\nPress No to choose the color from the image At the start of drawing, it takes the first point where the mouse begins",
       "Choose Color Option",   // هذا هو الـ caption
       MessageBoxButtons.YesNo,
       MessageBoxIcon.Question);

            if (result == DialogResult.Yes)
            {
                // اختيار اللون من القائمة
                using (ColorDialog cd = new ColorDialog())
                {
                    if (cd.ShowDialog() == DialogResult.OK)
                    {
                        currentColor = cd.Color;
                        MessageBox.Show("The color has been selected from the list:" + currentColor.ToString());
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else if (result == DialogResult.No)
            {
                // تفعيل وضع الالتقاط من الصورة
                pickingColorFromImage = true;
                //MessageBox.Show("اضغط على الصورة لاختيار اللون منها");
                //return false;
            }

            // اختيار اللون
            /*using (ColorDialog cd = new ColorDialog())
            {
                if (cd.ShowDialog() == DialogResult.OK)
                {
                    currentColor = cd.Color;
                }
                else
                {
                    return false;
                }
            }*/

            // إدخال سماكة الخط
            string inputWidth = Microsoft.VisualBasic.Interaction.InputBox(
               "Enter the line thickness (e.g., 2)", "line thickness", "2");

            if (!int.TryParse(inputWidth, out lineWidth))
            {
                MessageBox.Show("Invalid value for thickness.");
                return false;
            }

            // اختيار نوع التعبئة
            DialogResult fillChoice = MessageBox.Show("Do you want to fill the shape?", "Type of shape",
                MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question);

            if (fillChoice == DialogResult.Cancel)
                return false;

            fillMode = (fillChoice == DialogResult.Yes);
            return true;
        }

        void befor()
        {
            pictureBox3.Image = b;
        }

        void UndoStack()
        {
            if (b != null)
            {
                Undo.Push(new Bitmap(b));
                Redo.Clear();
            }
        }

        byte[] ImageReader(Bitmap image)
        {
            var picklock = image.LockBits(new Rectangle(0, 0, image.Width, image.Height),
                System.Drawing.Imaging.ImageLockMode.ReadOnly, image.PixelFormat);
            byte[] imagebyte = new byte[image.Width * image.Height * 4];
            Marshal.Copy(picklock.Scan0, imagebyte, 0, imagebyte.Length);
            image.UnlockBits(picklock);
            return imagebyte;
        }

        private void ImageWriter(byte[] imbyte, Bitmap image)
        {
            var piclock = image.LockBits(new Rectangle(0, 0, image.Width, image.Height),
                System.Drawing.Imaging.ImageLockMode.WriteOnly, image.PixelFormat);
            Marshal.Copy(imbyte, 0, piclock.Scan0, imbyte.Length);
            image.UnlockBits(piclock);
        }

        private void AdjustBrightness(int adjustment)
        {
            if (b == null) return;

            byte[] imagebyte = ImageReader(b);
            for (int i = 0; i < imagebyte.Length; i += 4)
            {
                imagebyte[i] = (byte)Math.Clamp(imagebyte[i] + adjustment, 0, 255);
                imagebyte[i + 1] = (byte)Math.Clamp(imagebyte[i + 1] + adjustment, 0, 255);
                imagebyte[i + 2] = (byte)Math.Clamp(imagebyte[i + 2] + adjustment, 0, 255);
            }
            ImageWriter(imagebyte, b);
            pictureBox2.Image = b;
        }

        private void InvertColors()
        {
            if (b == null) return;

            byte[] imagebyte = ImageReader(b);
            for (int i = 0; i < imagebyte.Length; i += 4)
            {
                imagebyte[i] = (byte)(255 - imagebyte[i]);
                imagebyte[i + 1] = (byte)(255 - imagebyte[i + 1]);
                imagebyte[i + 2] = (byte)(255 - imagebyte[i + 2]);
            }
            ImageWriter(imagebyte, b);
            pictureBox2.Image = b;
        }
        //-------------------------------------------------------------
        //-------------------------------------------------------------
        // 2)
        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog d = new OpenFileDialog();
            d.Filter = "PNG and JPG|*.jpg;*.png";
            if (d.ShowDialog() == DialogResult.Cancel)
                return;

            b = new Bitmap(d.FileName);
            b = new Bitmap(b);
            originalImage = new Bitmap(b); // Save original image copy
            currentUnfiltered = new Bitmap(b);
            currentUnfiltered2 = new Bitmap(b);

            pictureBox1.Image = b;
            pictureBox2.Image = b;

            //listView2.Items.Clear();
            // إضافة الأعمدة
            listView1.Columns.Clear();
            listView1.Columns.Add("Property", 200);
            listView1.Columns.Add("Value", 200);

            // إضافة العناصر
            listView1.Items.Add(new ListViewItem(new string[] { "Width", originalImage.Width.ToString(), "" }));
            listView1.Items.Add(new ListViewItem(new string[] { "Height", originalImage.Height.ToString(), "" }));
            listView1.Items.Add(new ListViewItem(new string[] { "Pixel Format", originalImage.PixelFormat.ToString(), "" }));
            listView1.Items.Add(new ListViewItem(new string[] { "Horizontal Resolution", originalImage.HorizontalResolution.ToString() }));
            listView1.Items.Add(new ListViewItem(new string[] { "Vertical Resolution", originalImage.VerticalResolution.ToString() }));
            listView1.Items.Add(new ListViewItem(new string[] { "Raw Format", originalImage.RawFormat.ToString() }));
            listView1.Items.Add(new ListViewItem(new string[] { "Physical Dimension", originalImage.PhysicalDimension.ToString() }));
            listView1.Items.Add(new ListViewItem(new string[] { "Flags", originalImage.Flags.ToString() }));
            listView1.View = View.Details;

            Undo.Clear();
            Redo.Clear();
        }


        private void infoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (b != null)
            {
                MessageBox.Show("Width  " + b.Width + "\n height  " + b.Height + "\n pixleformat  " + b.PixelFormat + "\n rawformat  " + b.RawFormat + "\n HorizontalResolution  " + b.HorizontalResolution
                   + "\n VerticalResolution  " + b.VerticalResolution, "manar", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Information);
            }
        }

        private void pictureBox2_MouseDown(object sender, MouseEventArgs e)
        {
            if (b == null) return;

            if (pickingColorFromImage == true)
            {
                Bitmap bmp = new Bitmap(pictureBox2.Image);
                if (e.X >= 0 && e.X < bmp.Width && e.Y >= 0 && e.Y < bmp.Height)
                {
                    currentColor = bmp.GetPixel(e.X, e.Y);
                }
                pickingColorFromImage = false; // نلغي وضع الالتقاط بعد أول استخدام
            }
            

            if (drawing == 6) // إذا كان وضع الرسم الحالي هو "كتابة نص"
            {
                //  إظهار مربع إدخال لطلب النص من المستخدم
                string inputText = Interaction.InputBox("Enter the text you want to write:", "Text Input", "");

                // إذا لم يُدخل المستخدم أي نص (أو ضغط "إلغاء")
                if (string.IsNullOrEmpty(inputText))
                {
                    drawing = 0; // إلغاء وضع الرسم
                    return;      // الخروج من التابع
                }

                //  إظهار مربع حوار لاختيار لون النص
                ColorDialog colorDialog = new ColorDialog();
                colorDialog.Color = Color.Black; // اللون الافتراضي هو الأسود

                // إذا ألغى المستخدم اختيار اللون
                if (colorDialog.ShowDialog() != DialogResult.OK)
                {
                    drawing = 0; // إلغاء وضع الرسم
                    return;
                }

                // حفظ اللون الذي اختاره المستخدم
                Color selectedColor = colorDialog.Color;

                // طلب حجم الخط من المستخدم (عن طريق مربع إدخال)
                string sizeInput = Interaction.InputBox("Enter the font size:", "font size", "20");

                // التحقق من أن المستخدم أدخل رقماً صالحاً للحجم
                if (!int.TryParse(sizeInput, out int fontSize))
                {
                    MessageBox.Show("Invalid font size."); // عرض رسالة خطأ
                    drawing = 0; // إلغاء وضع الرسم
                    return;
                }

                //  سؤال المستخدم إذا كان يريد الخط غامق (Bold) أم عادي
                DialogResult isBold = MessageBox.Show("Bold?", "font size", MessageBoxButtons.YesNo);

                // تحديد نمط الخط بناءً على اختيار المستخدم
                FontStyle style = isBold == DialogResult.Yes ? FontStyle.Bold : FontStyle.Regular;

                //  بدء الرسم على الصورة الحالية b
                using (Graphics g = Graphics.FromImage(b))
                {
                    // إنشاء كائن الخط حسب الحجم والنمط
                    System.Drawing.Font font = new System.Drawing.Font("Arial", fontSize, style);

                    // إنشاء فرشاة باللون الذي اختاره المستخدم
                    Brush brush = new SolidBrush(selectedColor);

                    // رسم النص في الموضع الذي نقرت فيه الفأرة (e.X, e.Y)
                    g.DrawString(inputText, font, brush, e.X, e.Y);
                }

                //  تحديث الصورة المعروضة في pictureBox2 بعد التعديل
                pictureBox2.Image = b;

                drawing = 0; // إنهاء وضع الرسم
                return;
            }




            if (drawing == 1 || drawing == 2 || drawing == 3 || drawing == 4 || drawing == 5)
            {
                mousex = e.X;
                mousey = e.Y;
                ismousedown = true;
            }
        }


        private void pictureBox2_MouseMove(object sender, MouseEventArgs e)
        {
            if (b == null || !ismousedown) return;
            // 1-2 عمل نسخة مؤقتة (Clone) من الصورة الأصلية للإرسم عليها مؤقتاً
            Bitmap temp = (Bitmap)b.Clone();
            // 1-3 استخدام كائن Graphics للرسم على الصورة المؤقتة
            using (Graphics g = Graphics.FromImage(temp))
            using (Pen pen = new Pen(currentColor, lineWidth))
            using (SolidBrush brush = new SolidBrush(currentColor))
            {
                // 1-4 حساب عرض وارتفاع المستطيل الذي يرسم الرسم بناءً على مكان ضغط الماوس ونقطة تحريك الماوس
                int rectw = Math.Abs(e.X - mousex);
                int recth = Math.Abs(e.Y - mousey);
                int rectx = Math.Min(e.X, mousex);
                int recty = Math.Min(e.Y, mousey);

                if (drawing == 1) // مستطيل
                {
                    Rectangle rect = new Rectangle(rectx, recty, rectw, recth);
                    if (fillMode)
                        g.FillRectangle(brush, rect);
                    else
                        g.DrawRectangle(pen, rect);
                }
                else if (drawing == 2) // معاينة القص
                {
                    Rectangle previewRect = new Rectangle(rectx, recty, rectw, recth);
                    using (Pen dashedPen = new Pen(Color.Red, 1))
                    {
                        dashedPen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dash;
                        g.DrawRectangle(dashedPen, previewRect);
                    }
                }

                else if (drawing == 3) // بيضوي
                {
                    Rectangle ellipseRect = new Rectangle(rectx, recty, rectw, recth);
                    if (fillMode)
                        g.FillEllipse(brush, ellipseRect);
                    else
                        g.DrawEllipse(pen, ellipseRect);
                }
                else if (drawing == 4) // إذا كان نوع الرسم المحدد هو "دائرة"
                {
                    // نحسب القطر (diameter) كأصغر قيمة بين العرض والطول
                    // الهدف هو الحفاظ على الشكل دائري تمامًا، وليس بيضاوي
                    int diameter = Math.Min(rectw, recth);

                    // تعديل موقع الزاوية العلوية اليسرى للدائرة (rectx, recty)
                    // حسب اتجاه سحب المستخدم للفأرة

                    // إذا كان المستخدم يسحب لأعلى ولليسار (↖)
                    // نحتاج لتحريك نقطة البداية إلى الأعلى واليسار بقدر القطر
                    if (e.X < mousex && e.Y < mousey)
                    {
                        rectx = mousex - diameter;
                        recty = mousey - diameter;
                    }
                    // إذا كان المستخدم يسحب لليسار فقط (←)
                    // نغير فقط الإحداثي X لبداية الرسم
                    else if (e.X < mousex)
                    {
                        rectx = mousex - diameter;
                    }
                    // إذا كان المستخدم يسحب لأعلى فقط (↑)
                    // نغير فقط الإحداثي Y لبداية الرسم
                    else if (e.Y < mousey)
                    {
                        recty = mousey - diameter;
                    }

                    // إنشاء مستطيل يمثل الإطار الذي ستُرسم داخله الدائرة
                    // هذا المستطيل يحدد مكان الدائرة وحجمها على اللوحة
                    Rectangle circleRect = new Rectangle(rectx, recty, diameter, diameter);

                    // تحقق مما إذا كان المستخدم يريد تعبئة الشكل أو فقط رسم حدوده
                    if (fillMode)
                        g.FillEllipse(brush, circleRect); // تعبئة الدائرة باللون المحدد في "brush"
                    else
                        g.DrawEllipse(pen, circleRect);   // رسم حدود الدائرة باستخدام "pen"
                }

                else if (drawing == 5) // مثلث متساوي الأضلاع
                {
                    int dx = e.X - mousex;
                    int baseLength = Math.Abs(dx);
                    int height = (int)(Math.Sqrt(3) / 2 * baseLength);

                    Point top = new Point(mousex + dx / 2, mousey);
                    Point left = new Point(mousex, mousey + height);
                    Point right = new Point(mousex + baseLength, mousey + height);

                    Point[] trianglePoints = { top, right, left };

                    if (fillMode)
                        g.FillPolygon(brush, trianglePoints);
                    else
                        g.DrawPolygon(pen, trianglePoints);
                }
            }

            pictureBox2.Image = (drawing == 2 && tempr != null) ? tempr : temp;
        }

        private void pictureBox2_MouseUp(object sender, MouseEventArgs e)
        {
            ismousedown = false;

            int rectw = Math.Abs(e.X - mousex);
            int recth = Math.Abs(e.Y - mousey);
            int rectx = Math.Min(e.X, mousex);
            int recty = Math.Min(e.Y, mousey);

            using (Graphics g = Graphics.FromImage(b))
            {
                if (drawing == 1)
                {
                    using (Pen pen = new Pen(currentColor, lineWidth))
                    {
                        if (fillMode)
                        {
                            using (SolidBrush brush = new SolidBrush(currentColor))
                            {
                                g.FillRectangle(brush, new Rectangle(rectx, recty, rectw, recth));
                            }
                        }
                        else
                        {
                            g.DrawRectangle(pen, new Rectangle(rectx, recty, rectw, recth));
                        }
                    }

                }
                else if (drawing == 2)
                {
                    rectw = Math.Abs(e.X - mousex);
                    recth = Math.Abs(e.Y - mousey);
                    rectx = Math.Min(e.X, mousex);
                    recty = Math.Min(e.Y, mousey);

                    if (rectw > 0 && recth > 0)
                    {
                        Rectangle cropRect = new Rectangle(rectx, recty, rectw, recth);
                        if (cropRect.Right <= b.Width && cropRect.Bottom <= b.Height && cropRect.X >= 0 && cropRect.Y >= 0)
                        {
                            try
                            {
                                tempr = b.Clone(cropRect, b.PixelFormat);
                                b = new Bitmap(tempr);
                                currentUnfiltered = new Bitmap(tempr);
                                pictureBox2.Image = b;
                            }
                            catch (Exception ex)
                            {
                                MessageBox.Show("حدث خطأ أثناء القص: " + ex.Message);
                            }
                        }
                        else
                        {
                            MessageBox.Show("منطقة القص خارج حدود الصورة.");
                        }
                    }
                }

                else if (drawing == 3)
                {
                    using (Pen pen = new Pen(currentColor, lineWidth))
                    {
                        if (fillMode)
                        {
                            using (SolidBrush brush = new SolidBrush(currentColor))
                            {
                                g.FillEllipse(brush, new Rectangle(rectx, recty, rectw, recth));
                            }
                        }
                        else
                        {
                            g.DrawEllipse(pen, new Rectangle(rectx, recty, rectw, recth));
                        }
                    }


                }
                using (Pen pen = new Pen(currentColor, lineWidth))
                using (SolidBrush brush = new SolidBrush(currentColor))
                    if (drawing == 4) // دائرة
                    {
                        int diameter = Math.Min(rectw, recth);
                        if (e.X < mousex && e.Y < mousey)
                        {
                            rectx = mousex - diameter;
                            recty = mousey - diameter;
                        }
                        else if (e.X < mousex)
                        {
                            rectx = mousex - diameter;
                        }
                        else if (e.Y < mousey)
                        {
                            recty = mousey - diameter;
                        }

                        Rectangle circleRect = new Rectangle(rectx, recty, diameter, diameter);

                        if (fillMode)
                            g.FillEllipse(brush, circleRect);
                        else
                            g.DrawEllipse(pen, circleRect);
                    }
                    else if (drawing == 5) // مثلث متساوي الأضلاع
                    {
                        int dx = e.X - mousex;// الفرق بين نقطة الماوس الحالية والنقطة التي بدأ منها الرسم
                        int baseLength = Math.Abs(dx);//طول قاعدة المثلث .
                        int height = (int)(Math.Sqrt(3) / 2 * baseLength);//ارتفاع المثلث (من الرأس إلى منتصف القاعدة).
                        //الارتفاع يساوي القاعدة ضرب جذر3 تقسيم 2 في المثلث متساوي الاضلاع

                        Point top = new Point(mousex + dx / 2, mousey);//نقطة بداية الرسم +طول القاعدة تقسيم اثنين لحساب اكس
                        Point left = new Point(mousex, mousey + height);//بداية الرسم أفقيًا.,ننزل للأسفل بمقدار ارتفاع المثلث.
                        Point right = new Point(mousex + baseLength, mousey + height);//نتحرك من اليسار لليمين بطول القاعدة.,ننزل للأسفل بمقدار ارتفاع المثلث

                        Point[] trianglePoints = { top, right, left };

                        if (fillMode)
                            g.FillPolygon(brush, trianglePoints);
                        else
                            g.DrawPolygon(pen, trianglePoints);
                    }
                    else if (drawing == 2 && tempr != null)
                    {
                        b = new Bitmap(tempr);
                    }
            }

            pictureBox2.Image = b;
            originalImage = new Bitmap(b);
            drawing = 0;
        }
        //-------------------------------------------------------------
        //-------------------------------------------------------------
        // 3)
        private void grayScaleToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            if (b == null) return;
            UndoStack();
            byte[] imagebyte = ImageReader(b);
            for (int i = 0; i < imagebyte.Length; i += 4)
            {
                int avg = (int)(0.1 * imagebyte[i] + 0.6 * imagebyte[i + 1] + 0.3 * imagebyte[i + 2]) / 3;
                imagebyte[i] = imagebyte[i + 1] = imagebyte[i + 2] = (byte)avg;
            }
            ImageWriter(imagebyte, b);
            pictureBox2.Image = b;
        }
        private void colorRToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (currentUnfiltered2 == null) return;

            UndoStack();
            Bitmap redBitmap = new Bitmap(currentUnfiltered2); // Use original image
            byte[] imagebyte = ImageReader(redBitmap);

            for (int i = 0; i < imagebyte.Length; i += 4)
            {
                imagebyte[i] = 0;    // Blue
                imagebyte[i + 1] = 0; // Green
                imagebyte[i + 3] = 255; // Alpha (شفافية كاملة)

            }

            ImageWriter(imagebyte, redBitmap);
            pictureBox2.Image = redBitmap;
            b = redBitmap;
        }

        private void colorBToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (currentUnfiltered2 == null) return;

            UndoStack();
            Bitmap blueBitmap = new Bitmap(currentUnfiltered2);
            byte[] imagebyte = ImageReader(blueBitmap);

            for (int i = 0; i < imagebyte.Length; i += 4)
            {
                imagebyte[i + 1] = 0; // Green
                imagebyte[i + 2] = 0; // Red
                imagebyte[i + 3] = 255; // Alpha (شفافية كاملة)

            }

            ImageWriter(imagebyte, blueBitmap);
            pictureBox2.Image = blueBitmap;
            b = blueBitmap;
        }

        private void colorGToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (currentUnfiltered2 == null) return;

            UndoStack();
            Bitmap greenBitmap = new Bitmap(currentUnfiltered2);
            byte[] imagebyte = ImageReader(greenBitmap);

            for (int i = 0; i < imagebyte.Length; i += 4)
            {
                imagebyte[i] = 0;     // Blue
                imagebyte[i + 2] = 0; // Red
                imagebyte[i + 3] = 255; // Alpha (شفافية كاملة)

            }

            ImageWriter(imagebyte, greenBitmap);
            pictureBox2.Image = greenBitmap;
            b = greenBitmap;
        }

        private void colorRGToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (currentUnfiltered2 == null) return;
            UndoStack();
            Bitmap RGBitmap = new Bitmap(currentUnfiltered2);
            byte[] imagebyte = ImageReader(RGBitmap);
            for (int i = 0; i < imagebyte.Length; i += 4)
            {
                imagebyte[i] = 0;
            }
            ImageWriter(imagebyte, RGBitmap);
            pictureBox2.Image = RGBitmap;
            b = RGBitmap;
        }

        private void colorRBToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (currentUnfiltered2 == null) return;
            UndoStack();
            Bitmap RBBitmap = new Bitmap(currentUnfiltered2);
            byte[] imagebyte = ImageReader(RBBitmap);
            for (int i = 0; i < imagebyte.Length; i += 4)
            {
                imagebyte[i + 1] = 0;
            }
            ImageWriter(imagebyte, RBBitmap);
            pictureBox2.Image = RBBitmap;
            b = RBBitmap;
        }

        private void colorGBToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (currentUnfiltered2 == null) return;
            UndoStack();
            Bitmap GBBitmap = new Bitmap(currentUnfiltered2);
            byte[] imagebyte = ImageReader(GBBitmap);
            for (int i = 0; i < imagebyte.Length; i += 4)
            {
                imagebyte[i+2] = 0;
            }
            ImageWriter(imagebyte, GBBitmap);
            pictureBox2.Image = GBBitmap;
            b = GBBitmap;
        }
        private void brightUpToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            if (b == null) return;
            UndoStack();
            AdjustBrightness(20);
        }
        private void brightDownToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            UndoStack();
            AdjustBrightness(-20);
        }
        private void toolStripMenuItem1_Click_1(object sender, EventArgs e)
        {
            if (b == null) return;
            UndoStack();
            InvertColors();
        }
        private void invertToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            UndoStack();
            InvertColors();
        }
        private void addFilterToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            if (b == null) return;

            // Open a Color Dialog to choose a filter color
            ColorDialog d = new ColorDialog();
            if (d.ShowDialog() == DialogResult.Cancel)
                return;

            Color filter = d.Color;

            // Show a dialog with a TrackBar control to choose the filter weight
            using (Form filterWeightForm = new Form())
            {
                // Setup TrackBar
                TrackBar trackBar = new TrackBar();
                trackBar.Minimum = 0;
                trackBar.Maximum = 100;
                trackBar.Value = 50; // Default value at 50 (50%)
                trackBar.Dock = DockStyle.Top;

                // Setup Label to display value
                Label label = new Label();
                label.Text = $"Filter Weight: {trackBar.Value / 100.0f:0.00}";
                label.Dock = DockStyle.Top;

                // Update label as user moves the TrackBar
                trackBar.ValueChanged += (s, args) =>
                {
                    label.Text = $"Filter Weight: {trackBar.Value / 100.0f:0.00}";
                };

                // Setup Apply button
                Button applyButton = new Button();
                applyButton.Text = "Apply";
                applyButton.Dock = DockStyle.Bottom;

                // Add event handler for Apply button
                applyButton.Click += (s, args) =>
                {
                    // Get the filter weight (scaled from 0.0 to 1.0)
                    float filterWeight = trackBar.Value / 100.0f;

                    // Push the current image to the undo stack
                    UndoStack();
                    byte[] imagebyte = ImageReader(b);

                    // Apply the filter with the selected weight
                    for (int i = 0; i < imagebyte.Length; i += 4)
                    {
                        // Blend the current color with the filter color based on the weight
                        imagebyte[i] = (byte)((imagebyte[i] * (1 - filterWeight)) + (filter.B * filterWeight)); // Blue
                        imagebyte[i + 1] = (byte)((imagebyte[i + 1] * (1 - filterWeight)) + (filter.G * filterWeight)); // Green
                        imagebyte[i + 2] = (byte)((imagebyte[i + 2] * (1 - filterWeight)) + (filter.R * filterWeight)); // Red
                    }

                    // Write the modified image back
                    ImageWriter(imagebyte, b);
                    pictureBox2.Image = b;

                    // Close the dialog after applying the filter
                    filterWeightForm.Close();
                };

                // Add controls to the dialog form
                filterWeightForm.Controls.Add(trackBar);
                filterWeightForm.Controls.Add(label);
                filterWeightForm.Controls.Add(applyButton);

                // Show the dialog and wait for user input
                filterWeightForm.ShowDialog();
            }
        }
        //-------------------------------------------------------------
        //-------------------------------------------------------------
        // 4)
        // Crop
        private void cropToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            UndoStack();
            drawing = 2;
            tempr = null;
            pictureBox2.Cursor = Cursors.Hand;
            currentUnfiltered = new Bitmap(b);
        }
        // Rotate
        private void rotateToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            // التأكد من وجود صورة قبل البدء
            if (b == null) return;

            // إنشاء نافذة جديدة لإدخال زاوية التدوير
            using (Form rotateForm = new Form())
            {
                // عنصر لاختيار زاوية التدوير (0 إلى 360)
                NumericUpDown numericUpDown = new NumericUpDown();
                numericUpDown.Minimum = 0;
                numericUpDown.Maximum = 360;
                numericUpDown.Value = 0;
                numericUpDown.Dock = DockStyle.Top;
                numericUpDown.DecimalPlaces = 0;

                // تسمية لعرض زاوية التدوير المختارة
                Label label = new Label();
                label.Text = $"Rotation Angle: {numericUpDown.Value}°";
                label.Dock = DockStyle.Top;

                // تحديث التسمية عندما تتغير قيمة الزاوية
                numericUpDown.ValueChanged += (s, args) =>
                {
                    label.Text = $"Rotation Angle: {numericUpDown.Value}°";
                };

                // زر لتنفيذ التدوير
                Button applyButton = new Button();
                applyButton.Text = "Apply Rotation";
                applyButton.Dock = DockStyle.Bottom;

                // عند الضغط على زر التدوير
                applyButton.Click += (s, args) =>
                {
                    float angle = (float)numericUpDown.Value;

                    // حفظ الحالة الحالية للتراجع
                    UndoStack();

                    // تحويل الزاوية من درجات إلى راديان
                    double radians = angle * Math.PI / 180;

                    // الحصول على أبعاد الصورة الأصلية
                    int oldWidth = b.Width;
                    int oldHeight = b.Height;

                    // حساب جيب وجيب تمام الزاوية (بشكل موجب)
                    double cos = Math.Abs(Math.Cos(radians));
                    double sin = Math.Abs(Math.Sin(radians));

                    // حساب أبعاد الصورة الجديدة بعد التدوير
                    int newWidth = (int)(oldWidth * cos + oldHeight * sin);
                    int newHeight = (int)(oldWidth * sin + oldHeight * cos);

                    // إنشاء صورة جديدة بأبعاد جديدة
                    Bitmap rotatedBmp = new Bitmap(newWidth, newHeight);
                    rotatedBmp.SetResolution(b.HorizontalResolution, b.VerticalResolution); // الحفاظ على الدقة

                    // بدء الرسم على الصورة الجديدة
                    using (Graphics g = Graphics.FromImage(rotatedBmp))
                    {
                        g.Clear(Color.White); // تعبئة الخلفية باللون الأبيض (أو يمكن استخدام شفاف)

                        // تحريك نقطة الأصل إلى مركز الصورة الجديدة
                        g.TranslateTransform(newWidth / 2f, newHeight / 2f);

                        // تدوير نظام الإحداثيات
                        g.RotateTransform(angle);

                        // إعادة نقطة الأصل إلى الزاوية اليسرى العليا للصورة الأصلية
                        g.TranslateTransform(-oldWidth / 2f, -oldHeight / 2f);

                        // رسم الصورة الأصلية في الوضع الجديد
                        g.DrawImage(b, new Point(0, 0));
                    }

                    // تحديث الصورة المعروضة في PictureBox
                    pictureBox2.Image = rotatedBmp;

                    // تحديث الصورة المستخدمة داخل الكود
                    b = rotatedBmp;

                    // إغلاق نافذة التدوير
                    rotateForm.Close();
                };

                // إضافة العناصر إلى نافذة التدوير
                rotateForm.Controls.Add(numericUpDown);
                rotateForm.Controls.Add(label);
                rotateForm.Controls.Add(applyButton);

                // عرض النافذة للمستخدم
                rotateForm.ShowDialog();
            }
        }
        // Flip H
        private void flipHToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            UndoStack();
            b.RotateFlip(RotateFlipType.RotateNoneFlipX);
            pictureBox2.Image = b;
        }
        // Flip V
        private void flipVToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            UndoStack();
            b.RotateFlip(RotateFlipType.RotateNoneFlipY);
            pictureBox2.Image = b;
        }
        // Flip BOTH
        private void flipBothToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            UndoStack();
            b.RotateFlip(RotateFlipType.RotateNoneFlipXY);
            pictureBox2.Image = b;
        }
        // RESIZE
        public Bitmap ResizeImage(Bitmap src, int newWidth, int newHeight)
        {
            Bitmap resized = new Bitmap(newWidth, newHeight);
            resized.SetResolution(src.HorizontalResolution, src.VerticalResolution);

            using (Graphics g = Graphics.FromImage(resized))
            {
                // تحسين جودة الصورة عند تصغير أو تكبير مع تقنية HighQualityBicubic لنتيجة سلسة
                g.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;
                g.DrawImage(src, new Rectangle(0, 0, newWidth, newHeight));
            }

            return resized;
        }
        private void resizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            UndoStack();
            // Ask user for new width and height
            string w = Interaction.InputBox("Enter new width:", "Resize", b.Width.ToString());
            string h = Interaction.InputBox("Enter new height:", "Resize", b.Height.ToString());

            if (int.TryParse(w, out int newWidth) && int.TryParse(h, out int newHeight))
            {
                // Validation: width and height must be positive and within reasonable limits
                if (newWidth > 0 && newHeight > 0 && newWidth <= b.Width && newHeight <= b.Height)
                {
                    b = ResizeImage(b, newWidth, newHeight);
                    pictureBox2.Image = b;
                }
                else
                {
                    // Warning: invalid values entered
                    MessageBox.Show("Please enter logical values",
                                    "Invalid input", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }
            else
            {
                // Warning: non-numeric input
                MessageBox.Show("Please enter numeric values only.",
                                "Invalid input", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }
        //-------------------------------------------------------------
        //-------------------------------------------------------------
        // 5)
        // Esc
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
            {
                drawing = 0;          // إلغاء وضع الرسم
                ismousedown = false;  // إيقاف أي عملية رسم جارية
                //pictureBox2.Image = new Bitmap(originalImage); // إعادة الصورة الأصلية أو الحالية

            }
        }
        // -Centered Rectangle
        private void DrawCenteredRectangle(int width, int height)
        {
            if (b == null) return;

            UndoStack();

            Rectangle rect = new Rectangle(
                (b.Width - width) / 2,
                (b.Height - height) / 2,
                width,
                height);

            using (Graphics g = Graphics.FromImage(b))
            {
                using (Pen pen = new Pen(rectangleColor, 2))
                using (SolidBrush brush = new SolidBrush(rectangleColor))
                {
                    if (fillRectangle)
                        g.FillRectangle(brush, rect);
                    else
                        g.DrawRectangle(pen, rect);
                }
            }


            pictureBox2.Image = b;
        }
        private void drawRectangleToolStripMenuItem_Click(object sender, EventArgs e)
        {

            if (b == null) return;

            // Ask for color
            ColorDialog cd = new ColorDialog();
            if (cd.ShowDialog() == DialogResult.Cancel) return;
            rectangleColor = cd.Color;

            // Ask if Fill or Stroke
            DialogResult result = MessageBox.Show("Do you want to fill the rectangle?\nClick Yes for Fill, No for Stroke.",
                                                  "Fill or Stroke?",
                                                  MessageBoxButtons.YesNoCancel,
                                                  MessageBoxIcon.Question);
            if (result == DialogResult.Cancel)
                return;

            fillRectangle = result == DialogResult.Yes;

            // Ask for size
            using (Form sizeForm = new Form())
            {
                sizeForm.Text = "Rectangle Size";

                NumericUpDown widthUpDown = new NumericUpDown() { Minimum = 10, Maximum = b.Width, Value = b.Width / 2, Dock = DockStyle.Top };
                NumericUpDown heightUpDown = new NumericUpDown() { Minimum = 10, Maximum = b.Height, Value = b.Height / 2, Dock = DockStyle.Top };

                Button applyBtn = new Button() { Text = "Draw Rectangle", Dock = DockStyle.Bottom };
                applyBtn.Click += (s, args) =>
                {
                    int rectWidth = (int)widthUpDown.Value;
                    int rectHeight = (int)heightUpDown.Value;

                    DrawCenteredRectangle(rectWidth, rectHeight);
                    sizeForm.Close();
                };

                sizeForm.Controls.Add(widthUpDown);
                sizeForm.Controls.Add(heightUpDown);
                sizeForm.Controls.Add(applyBtn);

                sizeForm.StartPosition = FormStartPosition.CenterParent;
                sizeForm.ShowDialog();
            }
        }
        // -Rectangle
        private void drawToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            if (!AskShapeOptions()) return;

            UndoStack();
            drawing = 1;
            pictureBox2.Cursor = Cursors.Hand;
        }
        // -Ellips
        private void drawEllipsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            if (!AskShapeOptions()) return;

            UndoStack();
            drawing = 3;
            pictureBox2.Cursor = Cursors.Hand;
        }
        // -Circle
        private void drawCircleToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            if (!AskShapeOptions()) return;

            UndoStack();
            drawing = 4;
            pictureBox2.Cursor = Cursors.Hand;
        }
        // -Tringle
        private void drawTringleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (b == null) return;
            if (!AskShapeOptions()) return;

            UndoStack();
            drawing = 5;
            pictureBox2.Cursor = Cursors.Hand;
        }
        // -Text
        private void addTextToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            if (b == null) return;

            UndoStack();
            drawing = 6;
            pictureBox2.Cursor = Cursors.Hand;
        }
        //-------------------------------------------------------------
        //-------------------------------------------------------------
        // 6)
        private void mix2imagesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // التأكد من أن الصورة الأولى موجودة
            if (b == null) return;

            using (OpenFileDialog dlg = new OpenFileDialog())
            {
                // تحديد أنواع الصور المسموح بفتحها
                dlg.Filter = "Image Files|*.bmp;*.jpg;*.jpeg;*.png;";
                if (dlg.ShowDialog() != DialogResult.OK)
                    return;

                // تحميل الصورة الثانية
                Bitmap secondImage = new Bitmap(dlg.FileName);

                // نستخدم أبعاد الصورة الأولى كأساس
                int width = b.Width;
                int height = b.Height;

                // طلب نسبة الدمج من المستخدم (0 إلى 100)
                string input = Microsoft.VisualBasic.Interaction.InputBox(
                    "أدخل نسبة دمج الصورة الثانية (0 إلى 100):",
                    "دمج الصور",
                    "50"
                );

                // التأكد من أن النسبة ضمن النطاق المسموح
                if (!int.TryParse(input, out int blendPercent) || blendPercent < 0 || blendPercent > 100)
                {
                    MessageBox.Show("الرجاء إدخال قيمة صحيحة بين 0 و 100.");
                    return;
                }

                // تحويل النسبة إلى قيمة بين 0 و 1
                float alpha = blendPercent / 100f;

                // حفظ الصورة الحالية في سجل التراجع قبل التعديل
                UndoStack();

                // إنشاء صورة جديدة بالحجم الكامل
                Bitmap mergedImage = new Bitmap(width, height);

                using (Graphics g = Graphics.FromImage(mergedImage))
                {
                    // رسم الصورة الأولى بكامل المساحة
                    g.DrawImage(b, new Rectangle(0, 0, width, height));

                    // إعداد الشفافية للصورة الثانية
                    ColorMatrix matrix = new ColorMatrix();
                    matrix.Matrix33 = alpha; // تعيين قيمة الشفافية

                    ImageAttributes attributes = new ImageAttributes();
                    attributes.SetColorMatrix(matrix, ColorMatrixFlag.Default, ColorAdjustType.Bitmap);

                    // رسم الصورة الثانية مع تمديدها لتطابق أبعاد الصورة الأولى
                    g.DrawImage(
                        secondImage,
                        new Rectangle(0, 0, width, height),                   // أين ترسم الصورة الثانية (تمدد على كامل المساحة)
                        0, 0, secondImage.Width, secondImage.Height,          // الجزء المرسوم من الصورة الأصلية
                        GraphicsUnit.Pixel,
                        attributes                                             // تطبيق الشفافية
                    );
                }

                // تحديث الصورة المعروضة
                b = mergedImage;
                originalImage = new Bitmap(mergedImage);
                pictureBox2.Image = mergedImage;
            }
        }
        //-------------------------------------------------------------
        //-------------------------------------------------------------
        // 7)
        private void undoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Undo.Count > 0 && b != null)
            {
                Redo.Push(new Bitmap(b));
                b = Undo.Pop();
                pictureBox2.Image = b;
            }
        }

        private void redoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (Redo.Count > 0 && b != null)
            {
                Undo.Push(new Bitmap(b));
                b = Redo.Pop();
                pictureBox2.Image = b;
            }
        }
        //-------------------------------------------------------------
        //-------------------------------------------------------------
        // 8)
        private void saveImageToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            if (b == null)
            {
                MessageBox.Show("No image to save.");
                return;
            }

            using (SaveFileDialog saveFileDialog = new SaveFileDialog())
            {
                saveFileDialog.Title = "Save Image";
                saveFileDialog.Filter = "PNG Image|*.png|JPEG Image|*.jpg;*.jpeg|BMP Image|*.bmp";
                saveFileDialog.DefaultExt = "png";
                saveFileDialog.AddExtension = true;

                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    ImageFormat format = ImageFormat.Png;

                    switch (Path.GetExtension(saveFileDialog.FileName).ToLower())
                    {
                        case ".jpg":
                        case ".jpeg":
                            format = ImageFormat.Jpeg;
                            break;
                        case ".bmp":
                            format = ImageFormat.Bmp;
                            break;
                    }

                    try
                    {
                        b.Save(saveFileDialog.FileName, format);
                        MessageBox.Show("Image saved successfully!");
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("Error saving image: " + ex.Message);
                    }
                }
            }
        }
        //-------------------------------------------------------------
        //                         AUDIO
        //-------------------------------------------------------------
        // 1)
        private void openAudioToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog a = new OpenFileDialog();
            a.Title = "Choose audio file";
            a.Filter = "MP3 | *.mp3";
            if (a.ShowDialog() == DialogResult.Cancel)
                return;
            s = new Mp3FileReader(a.FileName);

            listView2.Items.Add(new ListViewItem(new string[] {"Mp3",
            "SampleRate", s.Mp3WaveFormat.SampleRate.ToString()}));

            listView2.Items.Add(new ListViewItem(new string[] {"Wave",
            "SampleRate", s.WaveFormat.SampleRate.ToString()}));

            listView2.Items.Add(new ListViewItem(new string[] {"Mp3",
            "bps", s.Mp3WaveFormat.BitsPerSample.ToString()}));

            listView2.Items.Add(new ListViewItem(new string[] {"Wave",
            "bps", s.WaveFormat.BitsPerSample.ToString()}));
            listView2.View = View.Details;
            w = new WaveOut();
            w.Init(s);
            trackBar1.Maximum = 1000;
        }

        private void Play_Click(object sender, EventArgs e)
        {
            if (w == null) return;
            w.Play();
            timer1.Enabled = true;
        }

        private void Pause_Click(object sender, EventArgs e)
        {
            if (w == null) return;
            w.Pause();
            timer1.Enabled = false;
        }

        private void Stop_Click(object sender, EventArgs e)
        {
            if (w == null) return;
            w.Stop();
            s.Seek(0, System.IO.SeekOrigin.Begin);
            timer1.Enabled = false;
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            if (w == null) return;

            value = (trackBar1.Value * s.Length) / 1000;
            s.Seek(value, System.IO.SeekOrigin.Begin);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (w == null) return;
            trackBar1.Value = (int)((1000 * s.Position) / s.Length);
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        //-------------------------------------------------------------
        //-------------------------------------------------------------
        // 10)
        // ZOOM In/Out
        private float zoomFactor = 1.0f;
        private void ZoomImage(float factor)
        {
            zoomFactor *= factor; // تحديث عامل التكبير

            if (zoomFactor < 0.1f) zoomFactor = 0.1f;  // الحد الأدنى للتكبير
            if (zoomFactor > 5.0f) zoomFactor = 5.0f;  // الحد الأعلى للتكبير

            // حساب أبعاد الصورة بعد التكبير
            int newWidth = (int)(b.Width * zoomFactor);
            int newHeight = (int)(b.Height * zoomFactor);

            Bitmap zoomedImage = new Bitmap(newWidth, newHeight);

            using (Graphics g = Graphics.FromImage(zoomedImage))
            {
                g.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;

                // رسم الصورة مكبرة
                g.DrawImage(b, 0, 0, newWidth, newHeight);
            }

            pictureBox2.Image = zoomedImage;
            b = zoomedImage;

            // توسيط الصورة داخل PictureBox
            pictureBox2.SizeMode = PictureBoxSizeMode.CenterImage;
        }


        private void inToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ZoomImage(1.2f);

        }
        private void outToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ZoomImage(0.8f);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }
       
    }
}


