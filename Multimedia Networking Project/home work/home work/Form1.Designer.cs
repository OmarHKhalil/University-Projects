namespace home_work
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            pictureBox1 = new PictureBox();
            pictureBox2 = new PictureBox();
            menuStrip1 = new MenuStrip();
            fileToolStripMenuItem = new ToolStripMenuItem();
            openToolStripMenuItem = new ToolStripMenuItem();
            openAudioToolStripMenuItem = new ToolStripMenuItem();
            saveImageToolStripMenuItem1 = new ToolStripMenuItem();
            editToolStripMenuItem = new ToolStripMenuItem();
            infoToolStripMenuItem = new ToolStripMenuItem();
            convertToolStripMenuItem = new ToolStripMenuItem();
            grayScaleToolStripMenuItem = new ToolStripMenuItem();
            addFilterToolStripMenuItem1 = new ToolStripMenuItem();
            brightUpToolStripMenuItem = new ToolStripMenuItem();
            brightDownToolStripMenuItem = new ToolStripMenuItem();
            toolStripMenuItem1 = new ToolStripMenuItem();
            rGBToolStripMenuItem = new ToolStripMenuItem();
            colorRToolStripMenuItem = new ToolStripMenuItem();
            colorBToolStripMenuItem = new ToolStripMenuItem();
            colorGToolStripMenuItem = new ToolStripMenuItem();
            colorRGToolStripMenuItem = new ToolStripMenuItem();
            colorRBToolStripMenuItem = new ToolStripMenuItem();
            colorGBToolStripMenuItem = new ToolStripMenuItem();
            manipulationToolStripMenuItem = new ToolStripMenuItem();
            cropToolStripMenuItem1 = new ToolStripMenuItem();
            rotateToolStripMenuItem1 = new ToolStripMenuItem();
            flipHToolStripMenuItem = new ToolStripMenuItem();
            flipVToolStripMenuItem = new ToolStripMenuItem();
            flipBothToolStripMenuItem = new ToolStripMenuItem();
            resizeToolStripMenuItem = new ToolStripMenuItem();
            drawToolStripMenuItem = new ToolStripMenuItem();
            drawRectangleToolStripMenuItem = new ToolStripMenuItem();
            drawToolStripMenuItem1 = new ToolStripMenuItem();
            drawEllipsToolStripMenuItem = new ToolStripMenuItem();
            drawCircleToolStripMenuItem1 = new ToolStripMenuItem();
            drawTringleToolStripMenuItem = new ToolStripMenuItem();
            addTextToolStripMenuItem1 = new ToolStripMenuItem();
            mix2imagesToolStripMenuItem = new ToolStripMenuItem();
            zoomToolStripMenuItem = new ToolStripMenuItem();
            inToolStripMenuItem = new ToolStripMenuItem();
            outToolStripMenuItem = new ToolStripMenuItem();
            undoToolStripMenuItem = new ToolStripMenuItem();
            redoToolStripMenuItem = new ToolStripMenuItem();
            listView1 = new ListView();
            trackBar1 = new TrackBar();
            Play = new Button();
            Pause = new Button();
            Stop = new Button();
            timer1 = new System.Windows.Forms.Timer(components);
            listView2 = new ListView();
            Wave = new ColumnHeader();
            Property = new ColumnHeader();
            Value = new ColumnHeader();
            pictureBox3 = new PictureBox();
            comboBox1 = new ComboBox();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).BeginInit();
            menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)trackBar1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox3).BeginInit();
            SuspendLayout();
            // 
            // pictureBox1
            // 
            pictureBox1.Location = new Point(514, 52);
            pictureBox1.Margin = new Padding(3, 4, 3, 4);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(500, 500);
            pictureBox1.TabIndex = 0;
            pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            pictureBox2.Location = new Point(1042, 52);
            pictureBox2.Margin = new Padding(3, 4, 3, 4);
            pictureBox2.Name = "pictureBox2";
            pictureBox2.Size = new Size(500, 500);
            pictureBox2.TabIndex = 1;
            pictureBox2.TabStop = false;
            pictureBox2.MouseDown += pictureBox2_MouseDown;
            pictureBox2.MouseMove += pictureBox2_MouseMove;
            pictureBox2.MouseUp += pictureBox2_MouseUp;
            // 
            // menuStrip1
            // 
            menuStrip1.ImageScalingSize = new Size(20, 20);
            menuStrip1.Items.AddRange(new ToolStripItem[] { fileToolStripMenuItem, editToolStripMenuItem, undoToolStripMenuItem, redoToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Padding = new Padding(7, 3, 0, 3);
            menuStrip1.Size = new Size(1554, 30);
            menuStrip1.TabIndex = 2;
            menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            fileToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { openToolStripMenuItem, openAudioToolStripMenuItem, saveImageToolStripMenuItem1 });
            fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            fileToolStripMenuItem.Size = new Size(46, 24);
            fileToolStripMenuItem.Text = "File";
            // 
            // openToolStripMenuItem
            // 
            openToolStripMenuItem.Name = "openToolStripMenuItem";
            openToolStripMenuItem.Size = new Size(177, 26);
            openToolStripMenuItem.Text = "Open Picture";
            openToolStripMenuItem.Click += openToolStripMenuItem_Click;
            // 
            // openAudioToolStripMenuItem
            // 
            openAudioToolStripMenuItem.Name = "openAudioToolStripMenuItem";
            openAudioToolStripMenuItem.Size = new Size(177, 26);
            openAudioToolStripMenuItem.Text = "Open Audio";
            openAudioToolStripMenuItem.Click += openAudioToolStripMenuItem_Click;
            // 
            // saveImageToolStripMenuItem1
            // 
            saveImageToolStripMenuItem1.Name = "saveImageToolStripMenuItem1";
            saveImageToolStripMenuItem1.Size = new Size(177, 26);
            saveImageToolStripMenuItem1.Text = "Save Image";
            saveImageToolStripMenuItem1.Click += saveImageToolStripMenuItem1_Click;
            // 
            // editToolStripMenuItem
            // 
            editToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { infoToolStripMenuItem, convertToolStripMenuItem, rGBToolStripMenuItem, manipulationToolStripMenuItem, drawToolStripMenuItem, mix2imagesToolStripMenuItem, zoomToolStripMenuItem });
            editToolStripMenuItem.Name = "editToolStripMenuItem";
            editToolStripMenuItem.Size = new Size(88, 24);
            editToolStripMenuItem.Text = "Edit Tools";
            // 
            // infoToolStripMenuItem
            // 
            infoToolStripMenuItem.Name = "infoToolStripMenuItem";
            infoToolStripMenuItem.Size = new Size(228, 26);
            infoToolStripMenuItem.Text = "info";
            infoToolStripMenuItem.Click += infoToolStripMenuItem_Click;
            // 
            // convertToolStripMenuItem
            // 
            convertToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { grayScaleToolStripMenuItem, addFilterToolStripMenuItem1, brightUpToolStripMenuItem, brightDownToolStripMenuItem, toolStripMenuItem1 });
            convertToolStripMenuItem.Name = "convertToolStripMenuItem";
            convertToolStripMenuItem.Size = new Size(228, 26);
            convertToolStripMenuItem.Text = "Convert";
            // 
            // grayScaleToolStripMenuItem
            // 
            grayScaleToolStripMenuItem.Name = "grayScaleToolStripMenuItem";
            grayScaleToolStripMenuItem.Size = new Size(173, 26);
            grayScaleToolStripMenuItem.Text = "gray scale";
            grayScaleToolStripMenuItem.Click += grayScaleToolStripMenuItem_Click_1;
            // 
            // addFilterToolStripMenuItem1
            // 
            addFilterToolStripMenuItem1.Name = "addFilterToolStripMenuItem1";
            addFilterToolStripMenuItem1.Size = new Size(173, 26);
            addFilterToolStripMenuItem1.Text = "add filter";
            addFilterToolStripMenuItem1.Click += addFilterToolStripMenuItem1_Click;
            // 
            // brightUpToolStripMenuItem
            // 
            brightUpToolStripMenuItem.Name = "brightUpToolStripMenuItem";
            brightUpToolStripMenuItem.Size = new Size(173, 26);
            brightUpToolStripMenuItem.Text = "bright up";
            brightUpToolStripMenuItem.Click += brightUpToolStripMenuItem_Click_1;
            // 
            // brightDownToolStripMenuItem
            // 
            brightDownToolStripMenuItem.Name = "brightDownToolStripMenuItem";
            brightDownToolStripMenuItem.Size = new Size(173, 26);
            brightDownToolStripMenuItem.Text = "bright down";
            brightDownToolStripMenuItem.Click += brightDownToolStripMenuItem_Click;
            // 
            // toolStripMenuItem1
            // 
            toolStripMenuItem1.Name = "toolStripMenuItem1";
            toolStripMenuItem1.Size = new Size(173, 26);
            toolStripMenuItem1.Text = "invert";
            toolStripMenuItem1.Click += toolStripMenuItem1_Click_1;
            // 
            // rGBToolStripMenuItem
            // 
            rGBToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { colorRToolStripMenuItem, colorBToolStripMenuItem, colorGToolStripMenuItem, colorRGToolStripMenuItem, colorRBToolStripMenuItem, colorGBToolStripMenuItem });
            rGBToolStripMenuItem.Name = "rGBToolStripMenuItem";
            rGBToolStripMenuItem.Size = new Size(228, 26);
            rGBToolStripMenuItem.Text = "RGB";
            // 
            // colorRToolStripMenuItem
            // 
            colorRToolStripMenuItem.Name = "colorRToolStripMenuItem";
            colorRToolStripMenuItem.Size = new Size(151, 26);
            colorRToolStripMenuItem.Text = "Color R";
            colorRToolStripMenuItem.Click += colorRToolStripMenuItem_Click;
            // 
            // colorBToolStripMenuItem
            // 
            colorBToolStripMenuItem.Name = "colorBToolStripMenuItem";
            colorBToolStripMenuItem.Size = new Size(151, 26);
            colorBToolStripMenuItem.Text = "Color B";
            colorBToolStripMenuItem.Click += colorBToolStripMenuItem_Click;
            // 
            // colorGToolStripMenuItem
            // 
            colorGToolStripMenuItem.Name = "colorGToolStripMenuItem";
            colorGToolStripMenuItem.Size = new Size(151, 26);
            colorGToolStripMenuItem.Text = "Color G";
            colorGToolStripMenuItem.Click += colorGToolStripMenuItem_Click;
            // 
            // colorRGToolStripMenuItem
            // 
            colorRGToolStripMenuItem.Name = "colorRGToolStripMenuItem";
            colorRGToolStripMenuItem.Size = new Size(151, 26);
            colorRGToolStripMenuItem.Text = "Color RG";
            colorRGToolStripMenuItem.Click += colorRGToolStripMenuItem_Click;
            // 
            // colorRBToolStripMenuItem
            // 
            colorRBToolStripMenuItem.Name = "colorRBToolStripMenuItem";
            colorRBToolStripMenuItem.Size = new Size(151, 26);
            colorRBToolStripMenuItem.Text = "Color RB";
            colorRBToolStripMenuItem.Click += colorRBToolStripMenuItem_Click;
            // 
            // colorGBToolStripMenuItem
            // 
            colorGBToolStripMenuItem.Name = "colorGBToolStripMenuItem";
            colorGBToolStripMenuItem.Size = new Size(151, 26);
            colorGBToolStripMenuItem.Text = "Color GB";
            colorGBToolStripMenuItem.Click += colorGBToolStripMenuItem_Click;
            // 
            // manipulationToolStripMenuItem
            // 
            manipulationToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { cropToolStripMenuItem1, rotateToolStripMenuItem1, flipHToolStripMenuItem, flipVToolStripMenuItem, flipBothToolStripMenuItem, resizeToolStripMenuItem });
            manipulationToolStripMenuItem.Name = "manipulationToolStripMenuItem";
            manipulationToolStripMenuItem.Size = new Size(228, 26);
            manipulationToolStripMenuItem.Text = "Manipulation";
            // 
            // cropToolStripMenuItem1
            // 
            cropToolStripMenuItem1.Name = "cropToolStripMenuItem1";
            cropToolStripMenuItem1.Size = new Size(151, 26);
            cropToolStripMenuItem1.Text = "Crop";
            cropToolStripMenuItem1.Click += cropToolStripMenuItem1_Click;
            // 
            // rotateToolStripMenuItem1
            // 
            rotateToolStripMenuItem1.Name = "rotateToolStripMenuItem1";
            rotateToolStripMenuItem1.Size = new Size(151, 26);
            rotateToolStripMenuItem1.Text = "Rotate";
            rotateToolStripMenuItem1.Click += rotateToolStripMenuItem1_Click;
            // 
            // flipHToolStripMenuItem
            // 
            flipHToolStripMenuItem.Name = "flipHToolStripMenuItem";
            flipHToolStripMenuItem.Size = new Size(151, 26);
            flipHToolStripMenuItem.Text = "Flip H";
            flipHToolStripMenuItem.Click += flipHToolStripMenuItem_Click;
            // 
            // flipVToolStripMenuItem
            // 
            flipVToolStripMenuItem.Name = "flipVToolStripMenuItem";
            flipVToolStripMenuItem.Size = new Size(151, 26);
            flipVToolStripMenuItem.Text = "Flip V";
            flipVToolStripMenuItem.Click += flipVToolStripMenuItem_Click;
            // 
            // flipBothToolStripMenuItem
            // 
            flipBothToolStripMenuItem.Name = "flipBothToolStripMenuItem";
            flipBothToolStripMenuItem.Size = new Size(151, 26);
            flipBothToolStripMenuItem.Text = "Flip Both";
            flipBothToolStripMenuItem.Click += flipBothToolStripMenuItem_Click;
            // 
            // resizeToolStripMenuItem
            // 
            resizeToolStripMenuItem.Name = "resizeToolStripMenuItem";
            resizeToolStripMenuItem.Size = new Size(151, 26);
            resizeToolStripMenuItem.Text = "Resize";
            resizeToolStripMenuItem.Click += resizeToolStripMenuItem_Click;
            // 
            // drawToolStripMenuItem
            // 
            drawToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { drawRectangleToolStripMenuItem, drawToolStripMenuItem1, drawEllipsToolStripMenuItem, drawCircleToolStripMenuItem1, drawTringleToolStripMenuItem, addTextToolStripMenuItem1 });
            drawToolStripMenuItem.Name = "drawToolStripMenuItem";
            drawToolStripMenuItem.Size = new Size(228, 26);
            drawToolStripMenuItem.Text = "Drawing_Annotation";
            // 
            // drawRectangleToolStripMenuItem
            // 
            drawRectangleToolStripMenuItem.Name = "drawRectangleToolStripMenuItem";
            drawRectangleToolStripMenuItem.Size = new Size(236, 26);
            drawRectangleToolStripMenuItem.Text = "DrawRectangleCenter";
            drawRectangleToolStripMenuItem.Click += drawRectangleToolStripMenuItem_Click;
            // 
            // drawToolStripMenuItem1
            // 
            drawToolStripMenuItem1.Name = "drawToolStripMenuItem1";
            drawToolStripMenuItem1.Size = new Size(236, 26);
            drawToolStripMenuItem1.Text = "DrawRectangle";
            drawToolStripMenuItem1.Click += drawToolStripMenuItem1_Click;
            // 
            // drawEllipsToolStripMenuItem
            // 
            drawEllipsToolStripMenuItem.Name = "drawEllipsToolStripMenuItem";
            drawEllipsToolStripMenuItem.Size = new Size(236, 26);
            drawEllipsToolStripMenuItem.Text = "DrawEllips";
            drawEllipsToolStripMenuItem.Click += drawEllipsToolStripMenuItem_Click;
            // 
            // drawCircleToolStripMenuItem1
            // 
            drawCircleToolStripMenuItem1.Name = "drawCircleToolStripMenuItem1";
            drawCircleToolStripMenuItem1.Size = new Size(236, 26);
            drawCircleToolStripMenuItem1.Text = "DrawCircle";
            drawCircleToolStripMenuItem1.Click += drawCircleToolStripMenuItem1_Click;
            // 
            // drawTringleToolStripMenuItem
            // 
            drawTringleToolStripMenuItem.Name = "drawTringleToolStripMenuItem";
            drawTringleToolStripMenuItem.Size = new Size(236, 26);
            drawTringleToolStripMenuItem.Text = "DrawTringle";
            drawTringleToolStripMenuItem.Click += drawTringleToolStripMenuItem_Click;
            // 
            // addTextToolStripMenuItem1
            // 
            addTextToolStripMenuItem1.Name = "addTextToolStripMenuItem1";
            addTextToolStripMenuItem1.Size = new Size(236, 26);
            addTextToolStripMenuItem1.Text = "Add_Text";
            addTextToolStripMenuItem1.Click += addTextToolStripMenuItem1_Click;
            // 
            // mix2imagesToolStripMenuItem
            // 
            mix2imagesToolStripMenuItem.Name = "mix2imagesToolStripMenuItem";
            mix2imagesToolStripMenuItem.Size = new Size(228, 26);
            mix2imagesToolStripMenuItem.Text = "mix2images";
            mix2imagesToolStripMenuItem.Click += mix2imagesToolStripMenuItem_Click;
            // 
            // zoomToolStripMenuItem
            // 
            zoomToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { inToolStripMenuItem, outToolStripMenuItem });
            zoomToolStripMenuItem.Name = "zoomToolStripMenuItem";
            zoomToolStripMenuItem.Size = new Size(228, 26);
            zoomToolStripMenuItem.Text = "Zoom";
            // 
            // inToolStripMenuItem
            // 
            inToolStripMenuItem.Name = "inToolStripMenuItem";
            inToolStripMenuItem.Size = new Size(116, 26);
            inToolStripMenuItem.Text = "In";
            inToolStripMenuItem.Click += inToolStripMenuItem_Click;
            // 
            // outToolStripMenuItem
            // 
            outToolStripMenuItem.Name = "outToolStripMenuItem";
            outToolStripMenuItem.Size = new Size(116, 26);
            outToolStripMenuItem.Text = "Out";
            outToolStripMenuItem.Click += outToolStripMenuItem_Click;
            // 
            // undoToolStripMenuItem
            // 
            undoToolStripMenuItem.Name = "undoToolStripMenuItem";
            undoToolStripMenuItem.Size = new Size(57, 24);
            undoToolStripMenuItem.Text = "undo";
            undoToolStripMenuItem.Click += undoToolStripMenuItem_Click;
            // 
            // redoToolStripMenuItem
            // 
            redoToolStripMenuItem.Name = "redoToolStripMenuItem";
            redoToolStripMenuItem.Size = new Size(54, 24);
            redoToolStripMenuItem.Text = "redo";
            redoToolStripMenuItem.Click += redoToolStripMenuItem_Click;
            // 
            // listView1
            // 
            listView1.Location = new Point(3, 52);
            listView1.Name = "listView1";
            listView1.Size = new Size(483, 500);
            listView1.TabIndex = 3;
            listView1.UseCompatibleStateImageBehavior = false;
            listView1.SelectedIndexChanged += listView1_SelectedIndexChanged;
            // 
            // trackBar1
            // 
            trackBar1.Location = new Point(3, 883);
            trackBar1.Name = "trackBar1";
            trackBar1.Size = new Size(1025, 56);
            trackBar1.TabIndex = 5;
            trackBar1.Scroll += trackBar1_Scroll;
            // 
            // Play
            // 
            Play.Location = new Point(727, 574);
            Play.Name = "Play";
            Play.Size = new Size(114, 49);
            Play.TabIndex = 6;
            Play.Text = "Play";
            Play.UseVisualStyleBackColor = true;
            Play.Click += Play_Click;
            // 
            // Pause
            // 
            Pause.Location = new Point(727, 697);
            Pause.Name = "Pause";
            Pause.Size = new Size(114, 49);
            Pause.TabIndex = 7;
            Pause.Text = "Pause";
            Pause.UseVisualStyleBackColor = true;
            Pause.Click += Pause_Click;
            // 
            // Stop
            // 
            Stop.Location = new Point(727, 820);
            Stop.Name = "Stop";
            Stop.Size = new Size(114, 49);
            Stop.TabIndex = 8;
            Stop.Text = "Stop";
            Stop.UseVisualStyleBackColor = true;
            Stop.Click += Stop_Click;
            // 
            // timer1
            // 
            timer1.Tick += timer1_Tick;
            // 
            // listView2
            // 
            listView2.Columns.AddRange(new ColumnHeader[] { Wave, Property, Value });
            listView2.Location = new Point(3, 558);
            listView2.Name = "listView2";
            listView2.Size = new Size(483, 311);
            listView2.TabIndex = 9;
            listView2.UseCompatibleStateImageBehavior = false;
            // 
            // Wave
            // 
            Wave.Text = "Wave";
            // 
            // Property
            // 
            Property.Text = "Property";
            // 
            // Value
            // 
            Value.Text = "Value";
            // 
            // pictureBox3
            // 
            pictureBox3.Location = new Point(1042, 558);
            pictureBox3.Name = "pictureBox3";
            pictureBox3.Size = new Size(500, 381);
            pictureBox3.TabIndex = 10;
            pictureBox3.TabStop = false;
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(457, 0);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(151, 28);
            comboBox1.TabIndex = 12;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1554, 951);
            Controls.Add(comboBox1);
            Controls.Add(pictureBox3);
            Controls.Add(listView2);
            Controls.Add(Stop);
            Controls.Add(Pause);
            Controls.Add(Play);
            Controls.Add(trackBar1);
            Controls.Add(listView1);
            Controls.Add(pictureBox2);
            Controls.Add(pictureBox1);
            Controls.Add(menuStrip1);
            KeyPreview = true;
            MainMenuStrip = menuStrip1;
            Margin = new Padding(3, 4, 3, 4);
            Name = "Form1";
            Text = "en";
            Load += Form1_Load;
            KeyDown += Form1_KeyDown;
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox2).EndInit();
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)trackBar1).EndInit();
            ((System.ComponentModel.ISupportInitialize)pictureBox3).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private PictureBox pictureBox1;
        private PictureBox pictureBox2;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem fileToolStripMenuItem;
        private ToolStripMenuItem openToolStripMenuItem;
        private ToolStripMenuItem editToolStripMenuItem;
        private ToolStripMenuItem infoToolStripMenuItem;
        private ToolStripMenuItem undoToolStripMenuItem;
        private ToolStripMenuItem redoToolStripMenuItem;
        private ToolStripMenuItem mix2imagesToolStripMenuItem;
        private ToolStripMenuItem rGBToolStripMenuItem;
        private ToolStripMenuItem colorBToolStripMenuItem;
        private ToolStripMenuItem colorGToolStripMenuItem;
        private ToolStripMenuItem colorRGToolStripMenuItem;
        private ToolStripMenuItem colorRBToolStripMenuItem;
        private ToolStripMenuItem colorGBToolStripMenuItem;
        private ToolStripMenuItem convertToolStripMenuItem;
        private ToolStripMenuItem drawToolStripMenuItem;
        private ToolStripMenuItem drawRectangleToolStripMenuItem;
        private ToolStripMenuItem drawToolStripMenuItem1;
        private ToolStripMenuItem drawEllipsToolStripMenuItem;
        private ToolStripMenuItem drawCircleToolStripMenuItem1;
        private ToolStripMenuItem drawTringleToolStripMenuItem;
        private ToolStripMenuItem addTextToolStripMenuItem1;
        private ToolStripMenuItem manipulationToolStripMenuItem;
        private ToolStripMenuItem cropToolStripMenuItem1;
        private ToolStripMenuItem rotateToolStripMenuItem1;
        private ToolStripMenuItem flipHToolStripMenuItem;
        private ToolStripMenuItem flipVToolStripMenuItem;
        private ToolStripMenuItem flipBothToolStripMenuItem;
        private ToolStripMenuItem resizeToolStripMenuItem;
        private ListView listView1;
        private ToolStripMenuItem saveImageToolStripMenuItem1;
        private ToolStripMenuItem openAudioToolStripMenuItem;
        private TrackBar trackBar1;
        private Button Play;
        private Button Pause;
        private Button Stop;
        private System.Windows.Forms.Timer timer1;
        private ListView listView2;
        private ColumnHeader Wave;
        private ColumnHeader Property;
        private ColumnHeader Value;
        private PictureBox pictureBox3;
        private ToolStripMenuItem zoomToolStripMenuItem;
        private ToolStripMenuItem inToolStripMenuItem;
        private ToolStripMenuItem outToolStripMenuItem;
        private ComboBox comboBox1;
        private ToolStripMenuItem colorRToolStripMenuItem;
        private ToolStripMenuItem grayScaleToolStripMenuItem;
        private ToolStripMenuItem addFilterToolStripMenuItem1;
        private ToolStripMenuItem brightUpToolStripMenuItem;
        private ToolStripMenuItem toolStripMenuItem1;
        private ToolStripMenuItem brightDownToolStripMenuItem;
    }
}
