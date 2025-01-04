import UIKit

class ViewController: UIViewController, UIImagePickerControllerDelegate, UINavigationControllerDelegate {
    var imageView = UIImageView()

    override func viewDidLoad() {
        super.viewDidLoad()
        setupUI()
    }

    func setupUI() {
        let takePhotoButton = UIButton(type: .system)
        takePhotoButton.setTitle("Take Photo", for: .normal)
        takePhotoButton.addTarget(self, action: #selector(openCamera), for: .touchUpInside)
        
        view.addSubview(imageView)
        view.addSubview(takePhotoButton)
        
        // Layout
        imageView.frame = CGRect(x: 20, y: 100, width: 300, height: 300)
        takePhotoButton.frame = CGRect(x: 20, y: 420, width: 100, height: 50)
    }

    @objc func openCamera() {
        guard UIImagePickerController.isSourceTypeAvailable(.camera) else { return }
        let picker = UIImagePickerController()
        picker.sourceType = .camera
        picker.delegate = self
        present(picker, animated: true)
    }

    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey: Any]) {
        if let image = info[.originalImage] as? UIImage {
            imageView.image = image
            dismiss(animated: true) {
                self.shareImage(image)
            }
        }
    }

    func shareImage(_ image: UIImage) {
        let activityVC = UIActivityViewController(activityItems: [image], applicationActivities: nil)
        present(activityVC, animated: true)
    }
}
