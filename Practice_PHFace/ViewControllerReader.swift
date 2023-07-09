//
//  ViewControllerReader.swift
//  Practice_PHFace
//
//  Created by Jinwoo Kim on 7/10/23.
//

import SwiftUI

struct ViewControllerReader: UIViewControllerRepresentable {
    let handler: (UIViewController) -> Void
    
    @MainActor
    final class ViewController: UIViewController {
        var handler: (UIViewController) -> Void
        
        init(handler: @escaping (UIViewController) -> Void) {
            self.handler = handler
            super.init(nibName: nil, bundle: nil)
            view.backgroundColor = .clear
            view.isUserInteractionEnabled = false
        }
        
        @available(*, unavailable)
        required init?(coder: NSCoder) {
            fatalError("init(coder:) has not been implemented")
        }
        
        override func didMove(toParent parent: UIViewController?) {
            super.didMove(toParent: parent)
            handler(self)
        }
    }
    
    func makeUIViewController(context: Context) -> ViewController {
        .init(handler: handler)
    }
    
    func updateUIViewController(_ uiViewController: ViewController, context: Context) {
        uiViewController.handler = handler
    }
}

extension View {
    func viewController(_ handler: @escaping (UIViewController) -> Void) -> some View {
        background {
            ViewControllerReader(handler: handler)
        }
    }
}
