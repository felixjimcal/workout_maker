# workout_maker

⚠PROJECT DISCONTINUED ⚠<br>
<br>
<br>
Reasons:<br>
Fitness:<br>
* Theres no option for a Weider routine, actually is more like a fullbody. <br>

Tech:<br>
* QLinechart do not helps. Bad documentation, no refreshing guides. <br>
* QCustomplot has no support for modern Qt versions. <br>
<br>
<br>

Notes:<br>
Run FastAPI server: python -m uvicorn main:app --reload<br>
<br>
// Combo box with objects on it<br>
// https://www.bogotobogo.com/Qt/Qt5_QVariant_meta_object_system_MetaType.php<br>
// ui->comboBox->insertItem(0, "Beacon");<br>
// struct cat {<br>
//     int i = 0;<br>
//     std::string name = "Kiwi";<br>
// } gato;<br>
// QVariant v = QVariant::fromValue(gato);<br>
// ui->comboBox->insertItem(1, gato.name.c_str(), v);<br>
// QObject::connect(ui->comboBox, &QComboBox::currentIndexChanged, [&](int index) { indexChanged(index); });<br>
	
// Retrieve data<br>
// QVariant v = QVariant::fromValue(ui->listWidget->currentItem()->data(Qt::UserRole));<br>
// cat vClass = v.value<cat>();<br>
