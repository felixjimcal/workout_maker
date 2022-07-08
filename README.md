# workout_maker

Stopped:
Fitness:<br>
* Theres no option for a Weider routine, actually is more like a fullbody. <br>
<br>
Tech:<br>
* QLinechart do not helps. Bad documentation, no refreshing guides. <br>
* QCustomplot has no support for modern Qt versions. <br>
<br>
<br>

Notes:<br>
Run FastAPI server: python -m uvicorn main:app --reload
<br>
// Combo box with objects on it
// https://www.bogotobogo.com/Qt/Qt5_QVariant_meta_object_system_MetaType.php
// ui->comboBox->insertItem(0, "Beacon");
// struct cat {
//     int i = 0;
//     std::string name = "Kiwi";
// } gato;
// QVariant v = QVariant::fromValue(gato);
// ui->comboBox->insertItem(1, gato.name.c_str(), v);
// QObject::connect(ui->comboBox, &QComboBox::currentIndexChanged, [&](int index) { indexChanged(index); });
	
// Retrieve data
// QVariant v = QVariant::fromValue(ui->listWidget->currentItem()->data(Qt::UserRole));
// cat vClass = v.value<cat>();